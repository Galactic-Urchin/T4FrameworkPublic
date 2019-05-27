// Copyright 2019 Tech4 Labs. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "T4Engine/Classes/Action/T4ActionMinimal.h"

#include "T4Engine/Public/T4Engine.h"

#include "GameFramework/PlayerController.h"

#include "T4PlayerController.generated.h"

/**
  * http://api.unrealengine.com/KOR/Gameplay/Framework/Controller/PlayerController/index.html
 */
class AT4PlayerDefaultPawn;
class UT4SpringArmComponent;
class UT4CameraComponent;
class UT4NetReplicateComponent; // #42
class IT4PacketHandlerSC;
class IT4PacketHandlerCS;
class IT4GameObject;

UCLASS()
class T4FRAMEWORK_API AT4PlayerController : public APlayerController, public IT4PlayerController
{
	GENERATED_UCLASS_BODY()

public:
	void SetupInputComponent() override;
	void PostInitializeComponents() override;

	void TickActor(
		float InDeltaTime, 
		enum ELevelTick InTickType,
		FActorTickFunction& InThisTickFunction
	) override;

	/** If true, actor is ticked even if TickType==LEVELTICK_ViewportsOnly	 */
	bool ShouldTickIfViewportsOnly() const override; // #17

	void EndPlay(const EEndPlayReason::Type InEndPlayReason) override;

protected:
	void BeginPlay() override;

	void OnPossess(APawn* InPawn) override;
	void OnUnPossess() override;

public:
	// IT4Controller
	ET4LayerType GetLayerType() const override { return LayerType; }
	ET4ControllerType GetType() const override { return ET4ControllerType::Player; }

	bool SetTargetObject(const FT4ObjectID& InNewTargetID) override;
	void ClearTargetObject(bool bInSetDefaultPawn) override;

	bool HasTargetObject() const override { return TargetObjectID.IsValid(); }
	const FT4ObjectID& GetTargetObjectID() const override { return TargetObjectID; }
	IT4GameObject* GetTargetObject() const override;
	IT4ActionRoot* GetTargetObjectActionRoot() const override; // #23

	bool HasPlayingAction(const FT4ActionKey& InActionKey) const override; // #20

	IT4AIController* CastAIController() override { return nullptr; }
	IT4PlayerController* CastPlayerController() override { return static_cast<IT4PlayerController*>(this); }

public:
	// IT4PlayerController
	bool CheckAuthority() const override { return HasAuthority(); }

	AController* GetController() override; // #42

	UInputComponent* NewInputComponent() override;
	void SetInputComponent(UInputComponent* InInputComponent) override;
	void OnSetInputMode(ET4InputMode InMode) override;

	void RegisterNetGameplayComponent(UActorComponent* InComponent) override; // #42
	UActorComponent* GetNetGameplayComponent() const override { return NetGameplayComponent; } // #42

	FRotator GetViewControlRotation() const override;

	ET4CameraType GetCameraType() const override { return ET4CameraType::TPS; }

	FVector GetCameraLocation() const override;
	FRotator GetCameraRotation() const override;
	FVector GetCameraLookAtLocation() const override; // #30

	void SetCameraZoom(float InAmount) override;
	void SetCameraPitch(float InAmount) override;
	void SetCameraYaw(float InAmount) override;

	void SetFreeCameraMoveDirection(const FVector& InLocation) override;

	void SetCameraLock(bool bInLock) override;
	bool IsCameraLocked() const override { return bCameraMoveLocked; }

	bool GetMousePositionToWorldRay(
		FVector& OutStartPosition,
		FVector& OutStartDirection
	) override;

	void SetMouseCursorType(EMouseCursor::Type InMouseCursorType) override;
	void ShowMouseCursor(bool InShow) override;

#if WITH_EDITOR
	// see UGameViewportClient::InputKey
	bool EditorInputKey(FKey InKey, EInputEvent InEvent, float InAmountDepressed, bool bInGamepad) override; // #30

	// see UGameViewportClient::InputAxis
	bool EditorInputAxis(FKey InKey, float InDelta, float InDeltaTime, int32 InNumSamples, bool bInGamepad) override; // #30

	void EditorSetViewportClient(IT4EditorViewportClient* InEditorViewportClient) override
	{
		EditorViewportClient = InEditorViewportClient;
	}

	FOnViewTargetChanged& GetOnViewTargetChanged() override { return OnViewTargetChanged; } // #39
#endif

private:
	IT4GameObject* GetGameObject(const FT4ObjectID& InObjectID) const;

	void AttachCameraComponent(APawn* InOuter, USceneComponent* InParentComponent);
	void DetachCameraComponent();

	void T4SetMouseLocation(const int InX, const int InY); // #30
	bool T4GetMousePosition(float& InLocationX, float& InLocationY) const; // #30

private:
	ET4LayerType LayerType;
	FT4ObjectID TargetObjectID;

	TWeakObjectPtr<AT4PlayerDefaultPawn> CachedDefaultPawn;
	TWeakObjectPtr<UT4SpringArmComponent> CameraSpringArmComponent;
	TWeakObjectPtr<UT4CameraComponent> CameraComponent;

	UPROPERTY(Category=Network, VisibleAnywhere)
	UActorComponent* NetGameplayComponent; // #42

	bool bCameraMoveLocked;
	FVector2D SaveMouseLocation;

	float CachedCameraSpringTargetArmLength;
	FRotator CachedCameraRotation;

#if WITH_EDITOR
	IT4EditorViewportClient* EditorViewportClient; // #30
	FOnViewTargetChanged OnViewTargetChanged; // #39
#endif
};
