#include <iostream>
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;
using namespace std;

class MUSCLES{

    //This class is special for excercises funtion in the user interface.

    public:
    json data;

    // This function clears the terminal

    void ClearScreen(){
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }
    
    // 

     bool loadExercises(const string& filename = "muscle.json") {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "File was failed to open!" << endl;
            return false;
        }
        try {
            file >> data;
            file.close();
            return true;
        } catch (const json::exception& e) {
            cerr << "JSON parsing error: " << e.what() << endl;
            return false;
        }
    }

 // Shows Chest Excercises
    void ShowChest(){
        cout << "-PECTORIALIS MAJOR-" << endl;
        cout << "-------------------" << endl;
        for (const auto& exercise : data["chest"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
        
        return;
    }
    void ShowBack(){
        cout << "   BACK EXCERCISES   " << endl;
        cout << "---------------------" << endl;
        cout << "1 | Upper Traps" << endl;
        cout << "2 | Lower Traps" << endl;
        cout << "3 | Lats " << endl;
        cout << "4 | Erectors" << endl;
        cout << "---------------------" << endl;
        cout << "-Select Muscle Group: ";
       int choice = 0;
       cin >> choice;
            switch(choice){
                default : 
                    cout << "Please Select A Valid Muscle Group" << endl;
                case 1:
                    ClearScreen();
                    ShowUpperTraps();
                    break;
                case 2:
                    ClearScreen();
                    ShowLowerTraps();
                    break;
                case 3:
                    ClearScreen();
                    ShowLats();
                    break;
                case 4:
                    ClearScreen();
                    ShowErectors();
                    break;
                    
            }
        return;
    }
    void ShowUpperTraps(){
        cout << "-PARS DESCENDENS TRAPEZII-" << endl;
        cout << "--------------------------" << endl;
        for (const auto& exercise : data["back"]["uppertraps"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
        
        return;
    }
    void ShowLowerTraps(){
        cout << "-PARS TRANSVERSA TRAPEZII-" << endl;
        cout << "--------------------------" << endl;
        for (const auto& exercise : data["back"]["lowertraps"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
        
        return;
    }
    void ShowLats(){
        cout << "-LATTISIMUS DORSI-" << endl;
        cout << "------------------" << endl;
        for (const auto& exercise : data["back"]["lats"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowErectors(){
        cout << "-ERECTOR-SPINAE-" << endl;
        cout << "----------------" << endl;
        for (const auto& exercise : data["back"]["erectors"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowArms(){
        cout << "   ARM EXCERCISES   " << endl;
        cout << "---------------------" << endl;
        cout << "1 | Biceps " << endl;
        cout << "2 | Triceps" << endl;
        cout << "3 | Forearms" << endl;
        cout << "---------------------" << endl;
        cout << "-Select Muscle Group: ";
       int choice = 0;
       cin >> choice;
            switch(choice){
                default : 
                    cout << "Please Select A Valid Muscle Group" << endl;
                case 1:
                    ClearScreen();
                    ShowBiceps();
                    break;
                case 2:
                    ClearScreen();
                    ShowTriceps();
                    break;
                case 3:
                    ClearScreen();
                    ShowForearms();
                    break;
                    
            }
        return;
    }
    void ShowBiceps(){
        cout << "-BICEPS BRACHII-" << endl;
        cout << "----------------" << endl;
        for (const auto& exercise : data["arms"]["biceps"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowTriceps(){
        cout << "---------------------" << endl;
        cout << "1 | Lateral Head " << endl;
        cout << "2 | Long Head" << endl;
        cout << "---------------------" << endl;
        cout << "-Select Muscle Group: ";
       int choice = 0;
       cin >> choice;
            switch(choice){
                default : 
                    cout << "Please Select A Valid Muscle Group" << endl;
                case 1:
                    ClearScreen();
                    ShowTricepsLateral();
                    break;
                case 2:
                    ClearScreen();
                    ShowTricepsLong();
                    break;
                    
            }
        return;
    }
    void ShowTricepsLateral(){
        cout << "-TRICEPS BRACHII LATERALE-" << endl;
        cout << "--------------------------" << endl;
        for (const auto& exercise : data["arms"]["triceps"]["lateralhead"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowTricepsLong(){
        cout << "-TRICEPS BRACHII LONGUM-" << endl;
        cout << "------------------------" << endl;
        for (const auto& exercise : data["arms"]["triceps"]["longhead"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowForearms(){
        cout << "-ANTEBRACHIUM-" << endl;
        cout << "--------------" << endl;
        for (const auto& exercise : data["arms"]["forearms"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowShoulders(){
         cout << "-SHOULDER-EXCERCISES " << endl;
        cout << "----------------------" << endl;
        cout << "1 | Front Shoulder " << endl;
        cout << "2 | Middle Shoulder" << endl;
        cout << "3 | Rear Shoulder" << endl;
        cout << "---------------------" << endl;
        cout << "-Select Muscle Group: ";
       int choice = 0;
       cin >> choice;
            switch(choice){
                default : 
                    cout << "Please Select A Valid Muscle Group" << endl;
                case 1:
                    ClearScreen();
                    ShowFrontShoulder();
                    break;
                case 2:
                    ClearScreen();
                     ShowMiddleShoulder();
                    break;
                case 3:
                    ClearScreen();
                    ShowRearShoulder();
                    break;
                    
            }
        return;
    }
    void ShowFrontShoulder(){
        cout << "-ANTERRIOR DELTOID-" << endl;
        cout << "------------------" << endl;
        for (const auto& exercise : data["shoulders"]["anteriordeltoid"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowMiddleShoulder(){
        cout << "-LATERAL DELTOID-" << endl;
        cout << "-----------------" << endl;
        for (const auto& exercise : data["shoulders"]["lateraldeltoid"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowRearShoulder(){
        cout << "-POSTERIOR DELTOID-" << endl;
        cout << "------------------" << endl;
        for (const auto& exercise : data["shoulders"]["posteriordeltoid"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowAbs(){
         cout << "   AB EXCERCISES   " << endl;
        cout << "---------------------" << endl;
        cout << "1 | Packs " << endl;
        cout << "2 | Obliques" << endl;
        cout << "---------------------" << endl;
        cout << "-Select Muscle Group: ";
        int choice = 0;
        cin >> choice;
        switch(choice){
            default : 
            cout << "Please Select A Valid Muscle Group" << endl;
            case 1:
            ClearScreen();
            ShowPacks();
            break;
            case 2:
            ClearScreen();
            ShowObliques();
            break;
            
        }
        return;
    }
    void ShowPacks(){
        cout << "-RECTUS ABDOMINIS-" << endl;
        cout << "------------------" << endl;
        for (const auto& exercise : data["abs"]["rectusabdominis"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowObliques(){
        cout << "     -OBLIQUES-   " << endl;
        cout << "------------------" << endl;
        for (const auto& exercise : data["abs"]["obliques"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowLegs(){
         cout << "   LEG EXCERCISES   " << endl;
        cout << "---------------------" << endl;
        cout << "1 | Quadriceps" << endl;
        cout << "2 | Hamstrings" << endl;
        cout << "3 | Glutes " << endl;
        cout << "4 | Calves" << endl;
        cout << "---------------------" << endl;
        cout << "-Select Muscle Group: ";
       int choice = 0;
       cin >> choice;
            switch(choice){
                default : 
                    cout << "Please Select A Valid Muscle Group" << endl;
                case 1:
                    ClearScreen();
                    ShowQuads();
                    break;
                case 2:
                    ClearScreen();
                    ShowHams();
                    break;
                case 3:
                    ClearScreen();
                    ShowGlutes();
                    break;
                case 4:
                    ClearScreen();
                    ShowCalves();
                    break;
                    
            }
        return;
    }
    void ShowQuads(){
        cout << "-QUADRICEPS FEMORIS-" << endl;
        cout << "--------------------" << endl;
        for (const auto& exercise : data["legs"]["quadriceps"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowHams(){
        cout << "-HAMSTRINGS-" << endl;
        cout << "------------" << endl;
        for (const auto& exercise : data["legs"]["hamstrings"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowGlutes(){
        cout << "-REGIO GLUTEA-" << endl;
        cout << "---------------" << endl;
        for (const auto& exercise : data["legs"]["glutes"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }
    void ShowCalves(){
        cout << "-TRICEPS SURAE-" << endl;
        cout << "---------------" << endl;
        for (const auto& exercise : data["legs"]["calves"]) {
            cout << "- " << exercise.get<string>() << endl;
        }
    }

    void excerciseMenu(){
        ClearScreen();
        cout << "   EXCERCISE  MENU     " << endl;
        cout << "----------------------" << endl;
        cout << "1 | Chest" << endl;
        cout << "2 | Back" << endl;
        cout << "3 | Arms" << endl;
        cout << "4 | Abs" << endl;
        cout << "5 | Legs" << endl;
        cout << "6 | Go Back" << endl;
        cout << "----------------------" << endl;
        cout << "Select Your Choice: ";
        int choice;
        cin >> choice;
            switch(choice){
                default: 
                    cout << "Please Enter a Valid Choice: ";
                    cin >> choice;
                case 1:
                    ClearScreen();
                    ShowChest();
                    break;
                case 2:
                    ClearScreen();
                    ShowBack();
                    break;
                case 3:
                    ClearScreen();
                    ShowArms();
                    break;
                case 4:
                    ClearScreen();
                    ShowAbs();
                    break;
                case 5:
                    ClearScreen();
                    ShowLegs();
                    break;
                case 6:
                    ClearScreen();
                    return;

            } 
            cout << "-------------------------" << endl;
            int proceed = 0;
                while(proceed != 1){
                    cout << "  Enter 1 to return: ";
                    cin >> proceed;
                }
                ClearScreen();
                return;
    }

};

class Gym{
    public:
    

    //User's data
    struct User{
        char gender = 'S';
        float age = 0;
        float height = 0;
        float weight = 0;
    };
    //User's PR's (Personal Record)
    struct PRs{
        float BenchPress = 0;
        float Deadlift = 0;
        float Squat = 0;
        float OverheadPress = 0;
        float BarbellRow = 0;
        float PullUps = 0;
    };

    User user;
    PRs pr;
    MUSCLES muscles;
    
    // This function clears the terminal
    void ClearScreen() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    // Loads the user data or runs SingUp funtions if no data exist.

    void Login(){
        ifstream file("user_data.json"); // Reads from user_data.json file
            
            if(!file.is_open()){ //  If it can't, then it means there isn't a file so it initiates SignUp function
                cout << "Welcome To MuscleMass App!" << endl;
                SignUp();
                return;
            } 
            json j;
    try {
        file >> j;
        file.close();

        // If there is, then loads the data from json file to the user's struct details
        if (j.contains("user")) {
            if (j["user"].contains("gender") && j["user"]["gender"].is_string())
                user.gender = j["user"]["gender"].get<string>()[0];
            if (j["user"].contains("age"))
                user.age = j["user"]["age"].get<float>();
            if (j["user"].contains("height"))
                user.height = j["user"]["height"].get<float>();
            if (j["user"].contains("weight"))
                user.weight = j["user"]["weight"].get<float>();
        }

        // Same for pr's
        if (j.contains("prs")) {
            if (j["prs"].contains("benchpress"))
                pr.BenchPress = j["prs"]["benchpress"].get<float>();
            if (j["prs"].contains("deadlift"))
                pr.Deadlift = j["prs"]["deadlift"].get<float>();
            if (j["prs"].contains("squat"))
                pr.Squat = j["prs"]["squat"].get<float>();
            if (j["prs"].contains("overheadpress"))
                pr.OverheadPress = j["prs"]["overheadpress"].get<float>();
            if (j["prs"].contains("barbellrow"))
                pr.BarbellRow = j["prs"]["barbellrow"].get<float>();
            if (j["prs"].contains("pullups"))
                pr.PullUps = j["prs"]["pullups"].get<float>();
        }
        // If the file is broken then runs SignUp function again
    } catch (const json::exception& e) {
        cout << "Welcome To Muscle Mass App!";
        SignUp();
    }
}


// It's the first step of SignUp funtion, user enters gender(M/F). The code repeats itself as long as user enters a valid gender (M or F).
void EnterGender(){
        cout << "---------------------------" << endl;
        cout << "-Please-Sign-Up-First-" << endl;
        cout << "Enter Your Gender (M/F): ";
        cin >> user.gender;
            if(user.gender == 'F' || user.gender == 'M'){
                return;
            }
            else{
                while(user.gender != 'F' && user.gender !='M'){
                cout << "Please Enter A Valid Gender: ";
                cin >> user.gender;
                    if(user.gender == 'F' || user.gender == 'M'){
                        return;
                    }
                }
                return;
            }
    }
    // Second step of SignUp function, user enters age. The code repeats itself as long as user enters a valid age (0 or greater)
    void EnterAge(){
        cout << "Enter Your Age: ";
        cin >> user.age;
            if(user.age < 1){
                while(user.age < 1){
                cout << "Please Enter A Valid Age: ";
                cin >> user.age;
                }
                return;
            }
    }
    // Third step of SignUp function, user enters height. The code repeats itself as long as user enters a valid height (0 or greater).
    void EnterHeight(){
        cout << "Enter Your Height (CM): ";
        cin >> user.height;
            if(user.height < 1){
                while(user.height < 1){
                cout << "Please Enter A Valid Height: ";
                cin >> user.height;
                }
                return;
            }
    }
    // The last step of SignUp function, user enters weight. The code repeats itself as long as user enter a valid weight (0 or greater).
    void EnterWeight(){
        cout << "Enter Your Weight (KG): ";
        cin >> user.weight;
            if(user.weight < 1){
                while(user.weight < 1){
                cout << "Please Enter A Valid Weight: ";
                cin >> user.weight;
                }
            }
    }
    // User signs up, default gender is 'U' and the numbers are 0.

    void SignUp(){
        EnterGender();
        EnterAge();
        EnterHeight();
        EnterWeight();
        ClearScreen();
        SaveToJson();
    }

    // Saves the data from the struct to the json file.

    void SaveToJson(){
        json j;
        j["user"]["gender"] = string(1, user.gender);
        j["user"]["age"] = user.age;
        j["user"]["height"] = user.height;
        j["user"]["weight"] = user.weight;

        j["prs"]["benchpress"] = pr.BenchPress;
        j["prs"]["deadlift"] = pr.Deadlift;
        j["prs"]["squat"] = pr.Squat;
        j["prs"]["overheadpress"] = pr.OverheadPress;
        j["prs"]["barbellrow"] = pr.BarbellRow;
        j["prs"]["pullups"] = pr.PullUps;

        ofstream file("user_data.json");
            if(file.is_open()){
                file << j.dump(4);
                file.close();
                cout << "Information Saved Succesfuly!" << endl; 
            } else{
                cout << "Information Wasn't Saved Succesfuly!" << endl;
            }
        }
        //Shows user's details and pr's
        
        void ShowUser() {
    ifstream file("user_data.json");
    if (!file.is_open()) {
        cout << "User Data Not Found!" << endl;
        return;
    }

    json j;
    try {
        file >> j;   
        file.close();

        
        char gender = j["user"]["gender"].get<string>()[0];
        int age = j["user"]["age"];
        float height = j["user"]["height"];
        float weight = j["user"]["weight"];
        float benchpress = j["prs"]["benchpress"];
        float deadlift = j["prs"]["deadlift"];
        float squat = j["prs"]["squat"];
        float overheadpress = j["prs"]["overheadpress"];
        float barbellrow = j["prs"]["barbellrow"];
        float pullups = j["prs"]["pullups"];
        
        ClearScreen();
        cout << "----------------------------" << endl;
        cout << "Gender: " << gender << endl;
        cout << "Age: " << age << endl;
        cout << "Height: " << height << " CM" << endl;
        cout << "Weight: " << weight << " KG" << endl;
        cout << "-------------" << endl;
            if(benchpress != 0){
                cout << "Bench Press: " << benchpress << " KG" << endl;
            } if(deadlift != 0){
                cout << "Deadlift: " << deadlift << " KG" << endl;
            } if(squat != 0){
                cout << "Squat: " << squat << " KG" << endl;
            } if(overheadpress != 0){
                cout << "Overhead Press: " << overheadpress << " KG" << endl;
            } if(barbellrow != 0){
                cout << "Barbell Row: " << barbellrow << " KG" << endl;
            } if(pullups != 0){
                cout << "Weighted Pullups: " << pullups << " KG" << endl;
            }
    } catch (const json::exception& e) {
        cout << "Error reading JSON: " << e.what() << endl;
    }
    // As the default numbers are 0, if no PR entered displays nothing.
    interface();
}

        
    //User enters PR (Personal Record).
    void EnterPR(){
        ifstream file("user_data.json");
            if(!file.is_open()){
                cout << "An Error Occured!" << endl;
                return;
            }
        
        ClearScreen();
        cout << "------------------" << endl;
        cout << "1 | Bench Press" << endl;
        cout << "2 | Deadlift" << endl;
        cout << "3 | Squat" << endl;
        cout << "4 | Overhead Press" << endl;
        cout << "5 | Barbell Row" << endl;
        cout << "6 | Weighted Pullups" << endl;
        cout << "------------------" << endl;
        cout << "Select Your Execise: ";
        int choice;
        cin >> choice;
        switch(choice){
            default:
            cout << "Please Enter A Number Between 1-6: ";
            cin >> choice;
            case 1: {
                ClearScreen();
                cout << "------------"<< endl;
                cout << "Enter Your Pr: ";
                cin >> pr.BenchPress;
                if(pr.BenchPress < 0){
                    while(pr.BenchPress < 0){
                        cout << "------------"<< endl;
                        cout << "PR Cannot Be Negative Number, Please Try Again" << endl;
                        cout << "Enter Your Pr: ";
                        cin >> pr.BenchPress;
                    }
                    break;
                }
                ClearScreen();
                cout << "Your Bench PR Has Been Set To: " << pr.BenchPress <<" KG"<< endl;
                SaveToJson();
                break;
            }
            case 2: {
                ClearScreen();
                cout << "------------"<< endl;
                cout << "Enter Your Pr: ";
                cin >> pr.Deadlift;
                if(pr.Deadlift < 0){
                    while(pr.Deadlift < 0){
                        cout << "------------"<< endl;    
                        cout << "PR Cannot Be Negative Number, Please Try Again" << endl;
                        cout << "Enter Your Pr: ";
                        cin >> pr.Deadlift;
                    }
                    break;
                }
                ClearScreen();
                cout << "Your Deadlift PR Has Been Set To: " << pr.Deadlift <<" KG"<< endl;
                SaveToJson();
                break;
            }
            case 3: {
                ClearScreen();
                cout << "------------"<< endl;
                cout << "Enter Your Pr: ";
                cin >> pr.Squat;
                if(pr.Squat < 0){
                    while(pr.Squat < 0){
                        cout << "PR Cannot Be Negative Number, Please Try Again" << endl;
                        cout << "Enter Your Pr: ";
                        cin >> pr.Squat;
                    }
                    break;
                } 
                ClearScreen();      
                cout << "Your Squat PR Has Been Set To: " << pr.Squat <<" KG"<< endl;
                SaveToJson();
                break;
            case 4:
                ClearScreen();
                cout << "------------"<< endl;
                cout << "Enter Your Pr: ";
                cin >> pr.OverheadPress;
                if(pr.OverheadPress < 0){
                    while(pr.OverheadPress < 0){
                        cout << "PR Cannot Be Negative Number, Please Try Again" << endl;
                        cout << "Enter Your Pr: ";
                        cin >> pr.OverheadPress;
                    }
                    break;
                } 
                ClearScreen();      
                cout << "Your Overhead Press PR Has Been Set To: " << pr.OverheadPress <<" KG"<< endl;
                SaveToJson();
                break;
            }
            case 5:
                ClearScreen();
                cout << "------------"<< endl;
                cout << "Enter Your Pr: ";
                cin >> pr.BarbellRow;
                if(pr.BarbellRow < 0){
                    while(pr.BarbellRow < 0){
                        cout << "PR Cannot Be Negative Number, Please Try Again" << endl;
                        cout << "Enter Your Pr: ";
                        cin >> pr.BarbellRow;
                    }
                    break;
                } 
                ClearScreen();      
                cout << "Your Barbell Row PR Has Been Set To: " << pr.BarbellRow <<" KG"<< endl;
                SaveToJson();
                break;
            case 6:
                ClearScreen();
                cout << "------------"<< endl;
                cout << "Enter Your Pr: ";
                cin >> pr.PullUps;
                if(pr.PullUps < 0){
                    while(pr.PullUps < 0){
                        cout << "PR Cannot Be Negative Number, Please Try Again" << endl;
                        cout << "Enter Your Pr: ";
                        cin >> pr.PullUps;
                    }
                    break;
                } 
                ClearScreen();      
                cout << "Your Pullups PR Has Been Set To: " << pr.PullUps <<" KG"<< endl;
                SaveToJson();
                break;
            }
            
             interface();
        }
        // The app calculates BMR(Basal Metabolic Rate), and daily calories based on user's gender, age, height and weight using Harris-Benedict formula
        void CalculateDailyKcal(){
        ClearScreen();
        // BMR(♂) = 10 * weight + 6.25 * height - 5 * age + 5
        // BMR(♀) = 10 * weight + 6.25 * height - 5 * age -161
        float BMR;
        ifstream file("user_data.json");
        if(!file.is_open()){
            cout << "Failed To Load Information!" << endl;
            return;
        }
        
        char gender;
        float weight;
        float height;
        float age;
        
        json j;
        
        try {
            file >> j;
            file.close();
            gender = j["user"]["gender"].get<string>()[0];
            weight = j["user"]["weight"];
            height = j["user"]["height"];
            age = j["user"]["age"];
        }
        catch (const json::exception& e) {
            cout << "JSON error: " << e.what() << endl;
            return;
        }
        
        
        
        if(gender == 'M' || gender == 'm'){
            BMR = 10 * weight + 6.25 * height - 5 * age + 5;
        } if(gender == 'F' || gender == 'f'){
            BMR = 10 * weight + 6.25 * height - 5 * age - 161;
        } if(gender != 'f' &&  gender != 'F' &&  gender != 'm' &&  gender != 'M'){
            cout << "Gender Error Occured!" << endl;
            return;
        }
        cout << "----------------------------" << endl;
        cout << "How Often Do You Excercise ?" << endl;
        cout << "1 | Sedanter (Office Job or No Excercise)" << endl;
        cout << "2 | Not Often (1-2 Times Per Week)" << endl;
        cout << "3 | Mid (3-5 Times Per Week)" << endl;
        cout << "4 | High (6-7 Times Per Week)" << endl;
        cout << "5 | Very High (More Than Once A Day)" << endl;
        cout << "----------------------------" << endl;
        int choice = 0;
        float kcal;
        cin >> choice;
        switch(choice){
            case 1:
            kcal = BMR * 1.2;
            break;
            case 2:
            kcal = BMR * 1.375;
            break;
            case 3:
            kcal = BMR * 1.55;
            break;
            case 4:
            kcal = BMR * 1.725;
            break;
            case 5:
            kcal = BMR * 1.9;
            break;
            
            default:
            cout << "Error!" << endl;
            break;
            
        }
        ClearScreen();
        cout << "According To Your Information:" << endl;
        cout << "BMR: " << BMR << endl;
                cout << "Daily KCAL: " << kcal << endl; 
                interface();
                
                
            }
            
            // This function has nothing to do with user's details, user enters the weight and reps and the app calculates 1 repetition max using Epley's formula.
            void oneRepMax(){
                ClearScreen();
                cout << "----------------------------" << endl;
                //1rm = weight x (1+0.0333 x reps)
                float weight = 0;
                float rep = 0;
                cout << "  Enter The Weight: ";                      
                cin >> weight;
                cout << "  Enter Repetitions: ";
                cin >> rep;
                
                float onerepmax;
                
                onerepmax = weight * (1+0.0333 * rep);
                ClearScreen();                        
                cout << " Your 1 Rep Max Is: " << onerepmax <<" KG" << endl;
                interface();
                
            }   
            
            // Main menu shown after successful login or sign-up
            void interface(){
                cout << "----------------------------" << endl;
                cout << "  MUSCLE MASS FITNESS APP" << endl;
                cout << "----------------------------" << endl;
                cout << "1 | Show Profile" << endl;
                cout << "2 | Enter PR" << endl;
                cout << "3 | Calculate Daily KCAL" << endl;
                cout << "4 | Calculate 1 Rep Max" << endl;
                cout << "5 | Excercises" << endl;
                cout << "6 | Exit App"<< endl;
                cout << "----------------------------" << endl;
                cout << "  Enter Your Choice: ";
                int choice = 0;
                cin >> choice;
                switch(choice){
                    case 1:
                    ShowUser();
                    break;
                    case 2:
                    EnterPR();
                    break;
                    
                    case 3:
                    CalculateDailyKcal();
                    break;
                    
                    case 4:
                    oneRepMax();
                    break;
                    case 5:
                    muscles.loadExercises();
                    muscles.excerciseMenu();
                    interface();
                    break;
                    
                    case 6:
                    ClearScreen();
                    break;     
                    default:
                    break;
                }
                return;
            };
    };
        
        int main(){
            Gym app;
            
            app.Login();
            app.interface();
    app.ClearScreen();
    return 0;

}