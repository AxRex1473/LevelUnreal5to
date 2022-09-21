// Fill out your copyright notice in the Description page of Project Settings.
// Se crean las clases para los objetos 

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Score_Controller.generated.h"

UCLASS()
class YOURFIRSTPROJECT_API AScore_Controller : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScore_Controller();
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Widgets")
	TSubclassOf<class UUserWidget> ScoreTextWidget;
	TWeakObjectPtr<class UUserWidget> pScoreTextWidget;
	TWeakObjectPtr<class UTextBlock> pScoreText;

	UFUNCTION(BlueprintCallable, Category="Score")
	void IncreaseScore(int amount);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	int Score;

};
