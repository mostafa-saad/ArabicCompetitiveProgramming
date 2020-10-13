#include <bits/stdc++.h>
using namespace std;

class IDevice {
};

class ICameraDevice: public IDevice {
public:
	virtual string GetVersion() = 0;
	virtual bool Start() = 0;
	virtual bool Stop() = 0;
	virtual ~ICameraDevice() {}
};

class UbuntuDriverOpenSource: public ICameraDevice {
public:
	string GetVersion() {		return "Ubuntu OpenSource";	}
	bool Start() {		return true;	}
	bool Stop() {		return false;	}
	~UbuntuDriverOpenSource() {	}
};

class UbuntuDriver3rdParty: public ICameraDevice {
public:
	string GetVersion() {		return "Ubuntu 3rdParty";	}
	bool Start() {		return true;	}
	bool Stop() {		return false;	}
	~UbuntuDriver3rdParty() {
	}
};

class UbuntuDriverWindows10: public ICameraDevice {
public:
	string GetVersion() {
		return "Microsot Windows 10";
	}
	bool Start() {
		return true;
	}
	bool Stop() {
		return false;
	}
	~UbuntuDriverWindows10() {
	}
};

class App {
protected:
	string app_info;
public:
	virtual void Run() = 0;
	virtual void Shutdown() {	}
	virtual ~App() {	}
};

class CameraAppCheese: public App {
private:
	ICameraDevice* camera;
public:
	CameraAppCheese(ICameraDevice* camera) :camera(camera) {	}

	void Run() {
		// record images/videos
		for (int i = 0; i < 5; ++i) {
			cout << "CameraAppCheese - I am fast\n";
		}
	}
	~CameraAppCheese() {	}
};

class CameraAppKamoso: public App {
private:
	ICameraDevice* camera;
public:
	CameraAppKamoso(ICameraDevice* camera) :
			camera(camera) {
	}

	void Run() {
		// record images/videos
		for (int i = 0; i < 5; ++i) {
			cout << "CameraAppKamoso - I am slow\n";
		}
	}
	~CameraAppKamoso() {
	}
};

class UbuntuOS {
private:
	vector<IDevice*> devices;
	vector<App*> apps;
public:
	App* GetCameraApp(string app_name) {
		ICameraDevice* driver = new UbuntuDriverOpenSource();
		App* app = nullptr;

		if (app_name == "Cheese")		app = new CameraAppCheese(driver);
		else if (app_name == "Kamoso")	app = new CameraAppKamoso(driver);
		else							return nullptr;

		devices.push_back(driver);
		apps.push_back(app);
		return app;
	}
	void Shutdown() {
		for (App* app : apps)		app->Shutdown();
	}
	~UbuntuOS() {
		cout << "OS Terminate\n";
		Shutdown();
		for (App* app : apps)	delete app;
		apps.clear();
		for (IDevice* device : devices)		delete device;
		devices.clear();
	}
};

int main() {
	UbuntuOS os;

	App* app = os.GetCameraApp("Cheese");

	if (app != nullptr)
		app->Run();

	return 0;
}
