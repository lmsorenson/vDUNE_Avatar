#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PickupModel.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class UPickupModel : public UObject
{
	GENERATED_BODY()

public:
    void Initialize(FString name, FString details);

    void delegate_display(class ADuneAvatar * avatar_reference);

    UFUNCTION(BlueprintCallable, Category=Inventory)
    FString get_name() const;

    UFUNCTION(BlueprintCallable, Category=Inventory)
    FString get_details() const;

    /**
     * A pointer to the list widget.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category=Widgets)
    class UUserWidget * owner_;

protected:
	UPROPERTY(BlueprintReadonly, Category=Inventory)
	FString collectible_name_;

	UPROPERTY(BlueprintReadonly, Category=Inventory)
	FString collectible_details_;
};
