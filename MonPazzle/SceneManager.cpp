#include "SceneManager.h"
#include <stack>
#include "Scene.h"

namespace {
	const SceneID StartUp = SceneID::Title;
	std::stack<Scene> scenes;
	bool shouldCreateNewScene = false;
	SceneID nextScene = StartUp;
	bool shouldClearStack = false;
	bool shouldPopScene = false;
	bool shouldTerminateApp = false;
}

namespace SceneManager {
	void CreateNewScene();
	void ClearStack();

	void Init()
	{
		CreateNewScene();
	}

	bool Update() {
		if (scenes.empty())
			//é¿ç€Ç…ãÔëÃìIÇ»SceneÉNÉâÉXÇçÏÇÈÇ‹Ç≈false
			return false;
		scenes.top().Update();
		if (shouldPopScene) {
			scenes.pop();
			shouldPopScene = false;
		}
		if (shouldCreateNewScene) {
			CreateNewScene();
			shouldCreateNewScene = false;
		}
		return shouldTerminateApp;
	}

	void Draw() {
		if (scenes.empty())
			return;
		scenes.top().Draw();
	}

	void AskToCreateNewScene(const SceneID nextScene, const bool shouldClearStack)
	{
		shouldCreateNewScene = true;
		::nextScene = nextScene;
		::shouldClearStack = shouldClearStack;
	}
	void AskToPopScene()
	{
		shouldPopScene = true;
	}
	void AskToTerminateApp()
	{
		shouldTerminateApp = true;
	}
	void CreateNewScene() {
		if (shouldClearStack) {
			ClearStack();
			shouldClearStack = false;
		}
		switch (nextScene)
		{
		case SceneID::Title:
			return;
		}
	}
	void ClearStack() {
		while (!scenes.empty())
			scenes.pop();
	}
}