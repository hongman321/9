#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionJudgment.generated.h"

UCLASS()
class SAMPLECHAT_API UMyBlueprintFunctionJudgment : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// 스트라이크 개수를 판별하는 함수
	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static int32 CountStrikes(const FString& SecretNumber, const FString& PlayerGuess);

	// 볼 개수를 판별하는 함수
	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static int32 CountBalls(const FString& SecretNumber, const FString& PlayerGuess);

	// 결과를 "2S1B" 형식의 문자열로 반환하는 함수
	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static FString GetResultString(int32 Strikes, int32 Balls);

	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static bool CheckNumber(const FString& PlayerGuess);

	// 중복 없는 3자리 랜덤 숫자 생성
	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString GenerateUniqueThreeDigitNumber();

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString ExtractOnlyGuess(const FString& RawInput);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static bool IsGuessCommand(const FString& Input);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString RemoveSlashPrefix(const FString& Input);


};
