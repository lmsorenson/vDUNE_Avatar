#pragma once

#include "CoreMinimal.h"
#include "UserBase.h"
//#include "vDuneCore/Public/Decorator/DecoratorBase.h"
//#include "Interfaces/Tools/AvatarTool.h"
//#include "Interfaces/Tools/EAvatarTool.h"
#include "DuneAvatar.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class VDUNE_AVATAR_API ADuneAvatar : public AUserBase//, public DecoratorBase
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* camera_boom_;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* follow_camera_;
    
    /** MappingContext */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputMappingContext* DefaultMappingContext;

    /** Jump Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* JumpAction;

    /** Move Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* MoveAction;

    /** Look Input Action */
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
    UInputAction* LookAction;

    /** Collection Sphere */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Pickup, meta = (AllowPrivateAccess = "true"))
    class USphereComponent* collection_sphere_;

    /** Inventory */
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory, meta = (AllowPrivateAccess = "true"))
    TArray<class UPickupModel *>  collectibles_;
//
//    /** Interaction objects */
//    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Inventory, meta = (AllowPrivateAccess = "true"))
//    TMap<FString, class UViableInteraction *>  viable_interactions_;

protected:
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tools, EditFixedSize = "true")
//    TMap<EAvatarTool, TSubclassOf<UAvatarMode>>  available_tool_;
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Tools, EditFixedSize = "true")
//    TMap<EAvatarMode, TSubclassOf<UAvatarMode>>  available_mode_;
//
//    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Decorators)
//    TSubclassOf<class UUserWidget> decorator_widget_;

public:
	ADuneAvatar(const FObjectInitializer& ObjectInitializer);

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float base_turn_rate_;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float base_lookup_rate_;

protected:
    virtual void BeginPlay() override;
    virtual void Tick(float delta_seconds) override;

    /** Called for movement input */
    void Move(const FInputActionValue& Value);

    /** Called for looking input */
    void Look(const FInputActionValue& Value);

protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

//	UFUNCTION(BlueprintCallable, Category=Pickup)
//	void detect_viable_interactions();
//
//    UFUNCTION(BlueprintCallable, Category=Pickup)
//    void update_viable_interactions();
//
	UFUNCTION(BlueprintCallable, Category=Inventory)
	TArray<class UPickupModel*> get_collectibles() const;
//
//    UFUNCTION(BlueprintCallable, Category=Inventory)
//    class UUserWidget * display_pickup(TSubclassOf<class UAvatarMenu> menu_type);
//
//    UFUNCTION(BlueprintCallable, Category=Interfaces)
//    TMap<FString, class UViableInteraction *> get_viable_interactions() const;
//
//    UFUNCTION(BlueprintCallable, Category=Mode)
//    void use_tool(EAvatarTool tool);

public:
	FORCEINLINE class USpringArmComponent* get_camera_boom() const { return camera_boom_; }
	FORCEINLINE class UCameraComponent* get_follow_camera() const { return follow_camera_; }
    FORCEINLINE class USphereComponent* get_collection_sphere() const { return collection_sphere_; }

//    UFUNCTION(BlueprintCallable, Category=Mode)
//    void set_mode(EAvatarMode mode);

    bool add_collectible(class UPickupModel * collectible_data);

//    void try_interaction();
//
//    void set_inspect_mode();
//    void set_measure_mode();
//    void set_ball_drop_experiment_mode();
};



