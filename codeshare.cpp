#include <bits/stdc++.h>
using namespace std;
class Elevator
{
    enum Direction{ UP, DOWN };
    Direction direction;

   vector<int> requests = {};
    int min_floor; 
    int max_floor;
    int current_floor = 0; //ground floor

 public:
    Elevator() = default;
    Elevator(int min_floor, int max_floor) :
            min_floor(min_floor),
            max_floor(max_floor),
            {}
    ~Elevator() {};

    void start_elevator();

 private:
    void set_initial_request();
    void set_request();
    bool is_valid_request(int floor) const;
    void set_direction();

    int get_min_floor() const
    {
        return min_floor;
    }

    int get_max_floor() const
    {
        return max_floor;
    }

    int get_current_floor() const
    {
        return current_floor;
    }

    void set_current_floor(int floor)
    {
        current_floor = floor;
    }

   
 }; 

    void Elevator::set_initial_request() 
    {
       
        int dest_floor;

        cout << "\nEnter number of requests \n";
      cin >> num_of_reqs;

     cout << "\nEnter destination floor number.\n";
        cin >> dest_floor;
        requests.emplace_back(dest_floor);
        set_direction();

        for (size_t i = 1; i < num_of_reqs; ++i)
        {
            std::cin >> dest_floor;
            if (is_valid_request(dest_floor))
            {
                requests.emplace_back(dest_floor);
                set_current_capacity(1 + get_current_capacity());
            }

        }
    }

    void Elevator::set_request()
    {
        size_t num_of_reqs;
        int dest_floor;

      cout << "\nEnter number of requests \n";
       cin >> num_of_reqs;

       cout << "\nEnter destination floor number.\n";
       
    }

    bool Elevator::is_valid_request(int floor) const
    {
         if (direction == UP && floor < get_current_floor())
        {
            cout << "Elevator is going UP.\n";
            return false;
        }
        else if (direction == DOWN && floor > get_current_floor())
        {
            cout << "Elevator is going DOWN.\n";
            return false;
        }
        else if (floor > get_max_floor() || floor < get_min_floor())
        {
            cout << "This floor does not exist\n";
            return false;
        }
        else
        {
            return true;
        }
    }

    void Elevator::set_direction()
    {
        if (requests[0] > get_current_floor())
        {
            direction = UP;
        }
        else if (requests[0] < get_current_floor())
        {
            direction = DOWN;
        }
    }

    void Elevator::start_elevator()
    {
        int curr_floor = get_current_floor();
        set_initial_request(); 
        std::sort(requests.begin(), requests.end());

        while (!requests.empty())
        {
            if (direction == UP)
            {
                set_current_floor(requests[0]);
            }
            else if (direction == DOWN)
            {
                set_current_floor(requests[requests.size() - 1]);
            }
            curr_floor = get_current_floor();
            curr_capacity = get_current_capacity();

            auto curr_floor_req = std::find(requests.begin(), requests.end(), get_current_floor());
            while (curr_floor_req != requests.end())
            {
                requests.erase(curr_floor_req); 
                curr_capacity--;
                curr_floor_req = std::find(requests.begin(), requests.end(), get_current_floor());
            }

            set_current_capacity(curr_capacity);

            std::string dir;
            if (direction == UP)
            {
                dir = "UP";
            }
            else
            {       
                dir = "DOWN";
            }


            if (curr_floor == get_max_floor())
            {
                direction = DOWN;
            }
            else if (curr_floor == get_min_floor())
            {
                direction = UP;
            }

            if (current_capacity == 0) 
            {
                set_initial_request();
                sort(requests.begin(), requests.end());
            }
            else
            {
                set_request();
                sort(requests.begin(), requests.end());
            }
        }
    }

