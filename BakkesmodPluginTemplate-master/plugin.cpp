#include "pch.h"
#include "plugin.h"


BAKKESMOD_PLUGIN(HideScoreboard, "Hides the scoreboard", plugin_version, PLUGINTYPE_FREEPLAY)

std::shared_ptr<CVarManagerWrapper> _globalCvarManager;

void HideScoreboard::onLoad()
{
	_globalCvarManager = cvarManager;
	cvarManager->log("Plugin loaded!");
	std::string res = "2560x1440" ;
	//std::vector<Vector2> ColorVecBlue{0.0,0.0,255.0,255.0 } ;
	//std::vector<Vector2> ColorVecOrange{255.0,150.0,0.0,255.0 } ;
		if (res != "1920x1080") {
			gameWrapper->RegisterDrawable([this](CanvasWrapper canvas) {
				Render(canvas,1,2);
				});
			gameWrapper->RegisterDrawable([this](CanvasWrapper canvas1) {
				Render(canvas1,2,2);
				});
		}
	// !! Enable debug logging by setting DEBUG_LOG = true in logging.h !!
	//DEBUGLOG("$projectname$ debug mode enabled");

	// LOG and DEBUGLOG use fmt format strings https://fmt.dev/latest/index.html
	//DEBUGLOG("1 = {}, 2 = {}, pi = {}, false != {}", "one", 2, 3.14, true);

	//cvarManager->registerNotifier("my_aweseome_notifier", [&](std::vector<std::string> args) {
	//	LOG("Hello notifier!");
	//}, "", 0);

	//auto cvar = cvarManager->registerCvar("template_cvar", "hello-cvar", "just a example of a cvar");
	//auto cvar2 = cvarManager->registerCvar("template_cvar2", "0", "just a example of a cvar with more settings", true, true, -10, true, 10 );

	//cvar.addOnValueChanged([this](std::string cvarName, CVarWrapper newCvar) {
	//	LOG("the cvar with name: {} changed", cvarName);
	//	LOG("the new value is: {}", newCvar.getStringValue());
	//});

	//cvar2.addOnValueChanged(std::bind(&$projectname$::YourPluginMethod, this, _1, _2));

	// enabled decleared in the header
	//enabled = std::make_shared<bool>(false);
	//cvarManager->registerCvar("TEMPLATE_Enabled", "0", "Enable the TEMPLATE plugin", true, true, 0, true, 1).bindTo(enabled);

	//cvarManager->registerNotifier("NOTIFIER", [this](std::vector<std::string> params){FUNCTION();}, "DESCRIPTION", PERMISSION_ALL);
	//cvarManager->registerCvar("CVAR", "DEFAULTVALUE", "DESCRIPTION", true, true, MINVAL, true, MAXVAL);//.bindTo(CVARVARIABLE);
	//gameWrapper->HookEvent("FUNCTIONNAME", std::bind(&TEMPLATE::FUNCTION, this));
	//gameWrapper->HookEventWithCallerPost<ActorWrapper>("FUNCTIONNAME", std::bind(&$projectname$::FUNCTION, this, _1, _2, _3));
	//gameWrapper->RegisterDrawable(bind(&TEMPLATE::Render, this, std::placeholders::_1));


	//gameWrapper->HookEvent("Function TAGame.Ball_TA.Explode", [this](std::string eventName) {
	//	LOG("Your hook got called and the ball went POOF");
	//});
	// You could also use std::bind here
	//gameWrapper->HookEvent("Function TAGame.Ball_TA.Explode", std::bind(&$projectname$::YourPluginMethod, this);
}
void HideScoreboard::onUnload() {
	LOG("I was too cool for this world B'(");
}
void HideScoreboard::Render(CanvasWrapper canvas, int boxNum, int res) {
	std::vector<Vector2> pos;
	std::vector<Vector2> size = { {107, 111} }; // Assuming size is consistent for simplicity

	if (res != 1) {
		pos = { {1050, 0} };
		// Adjustments for Vec2 and size if necessary
	}
	else {
		pos = { {1050, 0} };
		// Adjustments for Vec2 and size if necessary
	}

	if (boxNum == 1) {
		canvas.SetColor('0', '0', '255', '255');
		// Adjust pos here if needed
	}
	else {
		pos = { {1364, 0} }; // Adjusting pos based on boxNum
		canvas.SetColor('255', '150', '0', '255');
	}

	// Make sure pos has been properly initialized before this call
	if (!pos.empty()) {
		cvarManager->log("got in canvas part");
		canvas.SetPosition(pos[0]);
		cvarManager->log("setposition");
		canvas.DrawBox(size[0]);
		cvarManager->log("draw box");
		canvas.FillBox(size[0]);
		cvarManager->log("filled box");
	}
	// Additional drawing operations...
	return;
}


