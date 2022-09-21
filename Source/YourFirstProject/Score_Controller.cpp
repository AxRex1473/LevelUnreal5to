// Fill out your copyright notice in the Description page of Project Settings.
// Se crean los objetos lo que es palpable


#include "Score_Controller.h"
#include "Blueprint/UserWidget.h"
#include "TextWidgetTypes.h"
#include "TextBlock.h"

// Sets default values
AScore_Controller::AScore_Controller() : Score(0)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AScore_Controller::BeginPlay()
{
	Super::BeginPlay();
	if (ScoreTextWidget)
	{
		pScoreTextWidget = CreateWidget<UUserWidget>(GetGameInstance(), ScoreTextWidget);

		if(pScoreTextWidget.IsValid())
		{
			pScoreTextWidget->AddToViewport();
			pScoreText = (UTextBlock*)pScoreTextWidget
				->GetWidgetFromName("Score_Text");
		}
	}
	
}

// Called every frame
void AScore_Controller::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScore_Controller::IncreaseScore(int amount)
{
	if(pScoreText.IsValid())
	{
		Score += amount;
		pScoreText -> SetText(FText::FromString(FString::FromInt(Score)));
	}
}
