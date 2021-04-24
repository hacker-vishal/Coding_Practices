#include<iostream>
#include<string>
using namespace std;


        class DB
        {
        public:
                virtual void Connect() = 0;
                virtual void Info() = 0;
        };


        void DbBusiness(DB* db)
        {
                cout << "DB Job started ...\n";
                db->Connect();
                db->Info();
                cout << "DB Job completed ...\n";
                cout << "______________________________\n";
        };
        //----------------------------
        class Socket
        {
        public:
                virtual void Connect() = 0;
                virtual void SocketDetails() = 0;
        };


        void SocketBusiness(Socket* sck)
        {
                cout << "Socket Job started ...\n";
                sck->Connect();
                sck->SocketDetails();
                cout << "Socket Job completed ...\n";
                cout << "______________________________\n";
        };
        //*****************************
        class Business :public DB, public Socket
        {
        public:
                void DB::Connect()
                {
                        cout << "Connect DB\n";
                }
                void Socket::Connect()
                {
                        cout << "Connect Socket\n";
                }
                void Info()
                {
                        cout << "DB Info\n";
                }
                void SocketDetails()
                {
                        cout << "Socket Info\n";
                }
        };


        int main()
        {
                Business bus;


                DbBusiness(&bus);
                SocketBusiness(&bus);


                return 0;
        }
