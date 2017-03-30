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
	   checkin.set_file_names("Checkin_log.txt", "Checkin_wait.txt", "Checkin_service.txt");
	   checkin.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   checkin.set_mu(53);
	   checkin.initialize();
	   checkin.set_seed(rd(), rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    security1;
	   security1.set_file_names("Security1_log.txt", "Security1_wait.txt", "Security1_service.txt");
	   security1.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   security1.set_mu(20);
	   security1.autogenerate_new_arrivals(false);
	   security1.initialize();
	   security1.set_seed(rd(), rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    security2;
	   security2.set_file_names("Security2_log.txt", "Security2_wait.txt", "Security2_service.txt");
	   security2.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   security2.set_mu(20);
	   security2.autogenerate_new_arrivals(false);
	   security2.initialize();
	   security2.set_seed(rd(), rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    security3;
	   security3.set_file_names("Security3_log.txt", "Security3_wait.txt", "Security3_service.txt");
	   security3.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   security3.set_mu(20);
	   security3.autogenerate_new_arrivals(false);
	   security3.initialize();
	   security3.set_seed(rd(), rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())

	   MM1_Queue    boarding;
	   boarding.set_file_names("Boarding_log.txt", "Boarding_wait.txt", "Boarding_service.txt");
	   boarding.set_lambda(6);   // for this assignment this is set to a variable from the for loop.
	   boarding.set_mu(80);
	   boarding.initialize();
	   boarding.set_seed(rd(), rd());   // I set the first one to 1 for testing, the others you should use two random seeds (rd(), rd())
	   //************************************************************


   for (; 
		//TODO: add is_within_error_range check
	   !checkin.is_within_error_range(0.002) ||
	   !security1.is_within_error_range(0.002) ||
	   !security2.is_within_error_range(0.002) ||
	   !security3.is_within_error_range(0.002) ||
	   !boarding.is_within_error_range(0.002)
       ;)
   {
	   Customer cust  = checkin.process_next_event();    // =  TODO: process next event;
	   Customer cust2  = security1.process_next_event();   // =  TODO: process next event;
	   Customer cust3  = security2.process_next_event();   // =  TODO: process next event;
	   Customer cust4  = security3.process_next_event();   // =  TODO: process next event;
	   Customer cust5 = boarding.process_next_event();   // =  TODO: process next event;

       if (cust.get_type() == Customer::COMPLETED())
       {
          switch(next)
          {
            case 0:
				//TODO add_external_arrival() for your security gates;
				security1.add_external_arrival();

                 break;
            case 1:
				//TODO add_external_arrival() for your security gates;
				security2.add_external_arrival();

                 break;
            case 2:
                //TODO add_external_arrival() for your security gates;
				security3.add_external_arrival();

                 break;
          }
          next++;
          if (next%3==0) next = 0;
       }
       if (cust2.get_type() == Customer::COMPLETED() || cust3.get_type() == Customer::COMPLETED() || cust4.get_type() == Customer::COMPLETED())
       {
		   //TODO add_external_arrival(); on your final boarding MM1_Queue object
		   boarding.add_external_arrival();

       }
   }



   //TODO Output statistics airport senario.
   std::ofstream myfile;
   myfile.open("Airport Stats.txt");
   cout << "Checkin Time" << checkin.get_current_time() << endl;
   checkin.output(); cout << endl << endl;
   security1.output(); cout << endl << endl;
   security2.output(); cout << endl << endl;
   security3.output(); cout << endl << endl;
   boarding.output(); cout << endl << endl;
   //**************************************************************************

   }

   return(0);
}

