#include <bits/stdc++.h>
using namespace std;

class CarSpecs {
private:
	string trim;
	string engine_type;
	pair<int, int> horsepower;
	string steering_ratio;
	// and more
public:
	 string& GetEngineType()  {
		return engine_type;
	}
	void SetEngineType( string& engineType) {
		engine_type = engineType;
	}
	pair<int, int> GetHorsepower()  {
		return horsepower;
	}
	void SetHorsepower(pair<int, int> horsepower) {
		this->horsepower = horsepower;
	}
	 string& GetSteeringRatio()  {
		return steering_ratio;
	}
	void SetSteeringRatio( string& steeringRatio) {
		steering_ratio = steeringRatio;
	}
	 string& GetTrim()  {
		return trim;
	}
	void SetTrim( string& trim) {
		this->trim = trim;
	}
};

class AutoTrader {
private:
	vector<CarSpecs> current_cars_vec;
public:
	void LoadDatabase() {
		// Fill current_cars_vec
	}

	bool search_match( CarSpecs &query_car) {
		for(auto available_car : current_cars_vec) {
			if(available_car.GetEngineType() != query_car.GetEngineType())	continue;
			if(available_car.GetHorsepower() != query_car.GetHorsepower())	continue;
			if(available_car.GetSteeringRatio() != query_car.GetSteeringRatio())	continue;
			if(available_car.GetTrim() != query_car.GetTrim())	continue;
			return true;
		}
		return false;
	}
};

/*

1- Above code violates encapsulation concept by forcing others to think how to compare to objects
   The right way, CarSpecs provides is_equal functionality

2- Also from code change perspective, every time we change the data members in CarSpecs (e.g. details of exterior shape)
   We will have to change AutoTrader class (2 classes changed).
   If CarSpecs provides is_equal functionality, other users won't need to do/care about the changes
   as they are still handled

3- On the other side, the code did not follow this nice tip:
	“Don’t ask for the information you need to do the work; ask the object that has the information to do the work for you.” Allen Holub

	We asked for all the gets to do the comparison! This should be the class responsibility
 */

int main() {
	return 0;
}
