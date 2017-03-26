/*
  A simple program that simulates 5 MM1 queues at an airport. The first queue
  feeds 3 other queues that work in parallel. These feed a final queue.
  Simulation runs until error below threshold and, at the end,
  a performance evaluation report is shown, and logs are generated
  for plotting and analysis.
*/

using namespace std;

#include <random>
#include "customer.h"
#include "mm1_queue.h"


std::random_device rd;

void pause()
{
 std::string sInputString;
 // Wait for input from stdin (the keyboard)
 cout << "Continue (y)?";
 std::cin >> sInputString;
}



int main(int argc, char* argv[])
{
   int next = 0;
//   test_random_number_generator();

   for (int cur_lambda = 3; cur_lambda < 34; cur_lambda++)
   {
      
	   //TODO Create MM1_Queue objects to capture the airport senario.
	   MM1_Queue    checkin;
	   checkin.set_file_names("ID_Check_log.txt", "ID_Check_wait.txt", "ID_Check_service.txt");
	   checkin.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   checkin.set_mu(53);
	   checkin.initialize();
	   checkin.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Security1;
	   Security1.set_file_names("Security1_log.txt", "Security1_wait.txt", "Security1_service.txt");
	   Security1.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Security1.set_mu(20);
	   Security1.autogenerate_new_arrivals(false);
	   Security1.initialize();
	   Security1.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Security2;
	   Security2.set_file_names("Security2_log.txt", "Security2_wait.txt", "Security2_service.txt");
	   Security2.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Security2.set_mu(20);
	   Security2.autogenerate_new_arrivals(false);
	   Security2.initialize();
	   Security2.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Security3;
	   Security3.set_file_names("Security3_log.txt", "Security3_wait.txt", "Security3_service.txt");
	   Security3.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Security3.set_mu(20);
	   Security3.autogenerate_new_arrivals(false);
	   Security3.initialize();
	   Security3.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    Boarding;
	   Boarding.set_file_names("Boarding_log.txt", "Boarding_wait.txt", "Boarding_service.txt");
	   Boarding.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   Boarding.set_mu(80);
	   Boarding.initialize();
	   Boarding.set_seed(1, rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())
	   //************************************************************


   for (; 
		//TODO: add is_within_error_range check
	   !checkin.is_within_error_range(0.002) ||
	   !Security1.is_within_error_range(0.002) ||
	   !Security2.is_within_error_range(0.002) ||
	   !Security3.is_within_error_range(0.002)
       ;)
   {
	   Customer cust  = checkin.process_next_event();    // =  TODO: process next event;
	   Customer cust2  = Security1.process_next_event();   // =  TODO: process next event;
	   Customer cust3  = Security2.process_next_event();   // =  TODO: process next event;
	   Customer cust4  = Security3.process_next_event();   // =  TODO: process next event;
	   Customer cust5 = Boarding.process_next_event();   // =  TODO: process next event;
	   //TODO: one more process_next_event for the last object.

       if (cust.get_type() == Customer::COMPLETED())
       {
          switch(next)
          {
            case 0:
				//TODO add_external_arrival() for your security gates;
				Security1.add_external_arrival();

                 break;
            case 1:
				//TODO add_external_arrival() for your security gates;
				Security2.add_external_arrival();

                 break;
            case 2:
                //TODO add_external_arrival() for your security gates;
				Security3.add_external_arrival();

                 break;
          }
          next++;
          if (next%3==0) next = 0;
       }
       if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED())
       {
		   //TODO add_external_arrival(); on your final boarding MM1_Queue object
		   Boarding.add_external_arrival();

       }
   }



   //TODO Output statistics airport senario.
   checkin.output(); cout << "*********" << endl;
   Security1.output(); cout << "*********" << endl;
   Security2.output(); cout << "*********" << endl;
   Security3.output(); cout << "*********" << endl;
   Boarding.output(); cout << "*********" << endl;


   //**************************************************************************



   }

   return(0);
}

