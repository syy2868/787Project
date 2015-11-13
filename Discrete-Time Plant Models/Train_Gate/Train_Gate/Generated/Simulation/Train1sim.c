#include "Train1sim.h"
#ifdef _MSC_VER
#include <Winsock2.h>
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#endif

int main(int argc, char *argv[])
{
    int       conn_s;                /*  connection socket         */
    const short int port = 61495;    /*  port number               */
    struct    sockaddr_in servaddr;  /*  socket address structure  */
    char      inbuffer[10240];      /*  character buffer          */
    int insize = 0;
    int tickCount = 0;
    // Declare and initialize variables
    #ifdef _MSC_VER
    WSADATA wsaData = {0};
    #endif
    int sResult = 0;
    int flag = 0;
    char* outbuffer = NULL;
    // Input:
    mxml_node_t *inxml = mxmlNewXML("1.0");
    mxml_node_t *tree = NULL;
    mxml_node_t *node = NULL;
    
    // Output
    mxml_node_t *outxml = mxmlNewXML("1.0");
    mxml_node_t *tick = mxmlNewElement(outxml, "Tick");
    // Declare Main FB instance (same as --run)
    Train1 _var;
    memset(&_var, 0, sizeof(Train1));
    Train1init(&_var);
    Train1_initXML(tick, &_var, "root");

    #ifdef _MSC_VER
    // Initialize Winsock
    sResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (sResult != 0) {
        printf("WSAStartup failed: %d\n", sResult);
        return 1;
    }

    #endif
    // Client socket
    if ( (conn_s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0 ) {
    	fprintf(stderr, "Simulator: Error creating listening socket: %d\n", conn_s);
    	exit(conn_s);
    }
    //  Set all bytes in socket address structure to
    //  zero, and fill in the relevant data members
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family      = AF_INET;
    #ifdef _MSC_VER
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
    #else
    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr.s_addr);
    #endif
    servaddr.sin_port        = htons(port);
    
    
    flag = 1;
    sResult = setsockopt(conn_s, IPPROTO_TCP, TCP_NODELAY, (char *) &flag, sizeof(int));
    if (sResult != 0) {
    	fprintf(stderr, "Simulator: Error setting TCP_NODELAY: %d\n", sResult);
    	exit(sResult);
    }
    // Connect to server.
    printf( "Trying to connect to TimeMe...\n");
    while ( connect( conn_s, (struct sockaddr*) &servaddr, sizeof(servaddr)) != 0) {
        #ifdef _MSC_VER
        		Sleep(10);
        #else
                sleep(10);
        #endif
        #ifdef _MSC_VER
        #endif
    }
    printf( "Connected to TimeMe\n");
    // Init TICK
    Train1run(&_var);
    
    // Tell IDE
        outbuffer = mxmlSaveAllocString(outxml, 
    	MXML_NO_CALLBACK); // whitespace_cb
    	if( outbuffer == NULL ){ // 
            printf("Things are broke. mxmlSaveAllocString returned NULL\n"); 
            scanf("%c\n", &inbuffer[0]);
    	}
        // Send buffer over TCP
        sResult = send( conn_s, outbuffer, strlen(outbuffer), 0 );
    	if (sResult < 0) {
    	    printf("send() failed with error: %d\n", sResult);
    #ifdef _MSC_VER
    		WSACleanup();
    		closesocket(conn_s);
    #else
    		close(conn_s);
    #endif
    		return 1;
    	}
    	printf("Sent: \n\n\"\"\"%s\"\"\"\n",outbuffer);
        fflush(stdout);
    #ifdef _MSC_VER
        free(outbuffer);
    #endif
    while(1){
        insize = recv(conn_s, inbuffer, 10240, 0);
        if( insize == 0 ){
            printf("Connection ended\n");
            break; // tcp connection end
        }
        if( insize < 0 ){
        	printf("recv() failed with error: %d\n", insize);
    #ifdef _MSC_VER
    		WSACleanup();
    		closesocket(conn_s);
    #else
    		close(conn_s);
    #endif
            return 1;
        }
    	inbuffer[insize] = '\0';
    	printf("Got: %d bytes: \n\n\"\"\"%s\"\"\"\n",insize, inbuffer);
        clearChildren(inxml);
    	tree = mxmlLoadString(inxml, inbuffer, MXML_OPAQUE_CALLBACK ); // MXML_ELEMENT );
    	
    	if( tree == NULL || tree->child == NULL )
    	{
    		printf("No xml commands found :(\n");
    		continue;
    	}
    	node = tree->child;
    	while( 1 )
    	{
    		if( node->value.opaque != NULL )
    		{
    			printf("%s\n", node->value.opaque);
    			if( strcasecmp(node->value.opaque,"Tick") == 0)
    			{
                    printf("Handling tick #%d\n", ++tickCount);
    				
    				handleTickCommand(tree, node, &_var);
    				Train1run(&_var);
    				
    				// Respond!!!
    				
    				outbuffer = mxmlSaveAllocString(outxml, 
    					MXML_NO_CALLBACK); // whitespace_cb
    				if( outbuffer != NULL ){
                         printf("Output XML: \n");
                         printf("\n%s\n", outbuffer);
                         fflush(stdout);
    				     // Send buffer over TCP
                         sResult = send( conn_s, outbuffer, strlen(outbuffer), 0 );
    #ifdef _MSC_VER
                         free(outbuffer);
    #endif
    		 			 if (sResult < 0) {
    					    printf("send() failed with error: %d\n", sResult);
    #ifdef _MSC_VER
    		WSACleanup();
    		closesocket(conn_s);
    #else
    		close(conn_s);
    #endif
    					    return 1;
    					 }
    				}
    				
    				//Clear input events
    				_var._input.events = 0;
    			}
    			else if( strcasecmp(node->value.opaque,"Stop") == 0)
    			{
    				printf("Stop command received. Exiting.\n");
    				exit(0);
    			}
    		}
    		if( node->next != NULL )
            { 
    			node = node->next;
    		}else
    			break;
    	}
            printf("Handle RECV xml DONE @ end of tick %d\n", tickCount);
    	
    }
    #ifdef _MSC_VER
    WSACleanup();
    closesocket(conn_s);
    #else
    close(conn_s);
    #endif
    return 1;
}


void handleTickCommand(mxml_node_t* tree, mxml_node_t* tickNode, Train1* me)
{
    mxml_node_t *event, *var;
    const char* nameAttr;
    const char* valueAttr;

    printf("Handle tick\n");
    // Get input events
    event = mxmlFindElement(tickNode, tree, "Event",
                           NULL, NULL,
                           MXML_DESCEND);
    while( event != NULL )
    {
        if(  strcmp(event->value.opaque, "Event") == 0  )
        {
            nameAttr = mxmlElementGetAttr ( event, "Name" );
            valueAttr = mxmlElementGetAttr ( event, "Value" );
            
            if( nameAttr != NULL && valueAttr != NULL)
            {
                if( strcasecmp(valueAttr, "Present") == 0 )
                {
                    printf("Event Present Name=%s\n", nameAttr);
                    if( strcasecmp(nameAttr, "update") == 0 )
                    {
                        me->_input.event.update = 1;
                    }
                }
                else
                {
                    printf("Event Absent Name=%s\n", nameAttr); 
                    // skip / who cares
                }
            }
        }
        event = event->next;
    }
    
    var = mxmlFindElement(tickNode, tree, "Var",
                           NULL, NULL,
                           MXML_DESCEND);
    // Get input data
    while( var != NULL )
    {
        if( strcmp(var->value.opaque, "Var") == 0 )
        {
            nameAttr = mxmlElementGetAttr ( var, "Name" );
            valueAttr = mxmlElementGetAttr ( var, "Value" );
            
            if( nameAttr != NULL && valueAttr != NULL)
            {
                // Set var value
                printf("Var Name=%s Value=%s\n", nameAttr, valueAttr);
                if( strcasecmp(nameAttr, "x") == 0 )
                {
                    stringToVoid(valueAttr, IEC_REAL, 1, 
                    &me->_x);
                }
            }
        }
        var = var->next;
    }
}

