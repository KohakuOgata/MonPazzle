#pragma once

enum class SceneID;

namespace SceneManager {
#ifdef SYSTEM_H
	void Init();
	bool Update();
	void Draw();
#endif // SYSTEM_H
	void AskToCreateNewScene(const SceneID nextScene, const bool shouldClearStack);
	void AskToPopScene();
	void AskToTerminateApp();
}

enum class SceneID
{
	Title
};
