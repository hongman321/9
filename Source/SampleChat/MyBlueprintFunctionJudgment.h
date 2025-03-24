#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "MyBlueprintFunctionJudgment.generated.h"

UCLASS()
class SAMPLECHAT_API UMyBlueprintFunctionJudgment : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// ��Ʈ����ũ ������ �Ǻ��ϴ� �Լ�
	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static int32 CountStrikes(const FString& SecretNumber, const FString& PlayerGuess);

	// �� ������ �Ǻ��ϴ� �Լ�
	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static int32 CountBalls(const FString& SecretNumber, const FString& PlayerGuess);

	// ����� "2S1B" ������ ���ڿ��� ��ȯ�ϴ� �Լ�
	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static FString GetResultString(int32 Strikes, int32 Balls);

	UFUNCTION(BlueprintCallable, Category = "NumberBaseball")
	static bool CheckNumber(const FString& PlayerGuess);

	// �ߺ� ���� 3�ڸ� ���� ���� ����
	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString GenerateUniqueThreeDigitNumber();

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString ExtractOnlyGuess(const FString& RawInput);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static bool IsGuessCommand(const FString& Input);

	UFUNCTION(BlueprintCallable, Category = "Judgment")
	static FString RemoveSlashPrefix(const FString& Input);


};
