// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionJudgment.generated.h"

/**
 * 
 */
UCLASS()
class SAMPLECHAT_API UMyBlueprintFunctionJudgment : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static int32 CountStrikes(const FString& SecretNumber, const FString& PlayerGuess);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static int32 CountBalls(const FString& SecretNumber, const FString& PlayerGuess);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString GetResultString(int32 Strikes, int32 Balls);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static bool CheckNumber(const FString& PlayerGuess);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString GenerateUniqueThreeDigitNumber();

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString ExtractOnlyGuess(const FString& RawInput);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static bool IsGuessCommand(const FString& Input);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString RemoveSlashPrefix(const FString& Input);



};
