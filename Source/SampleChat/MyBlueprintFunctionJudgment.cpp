#include "MyBlueprintFunctionJudgment.h"



int32 UMyBlueprintFunctionJudgment::CountStrikes(const FString& SecretNumber, const FString& PlayerGuess)
{
	if (SecretNumber.Len() < 3 || PlayerGuess.Len() < 3)
	{
		return 0; // 유효하지 않으면 비교하지 않음
	}

	int32 Strikes = 0;
	for (int32 i = 0; i < 3; i++)
	{
		if (SecretNumber[i] == PlayerGuess[i])
		{
			Strikes++;
		}
	}

	return Strikes;
}

int32 UMyBlueprintFunctionJudgment::CountBalls(const FString& SecretNumber, const FString& PlayerGuess)
{
	if (SecretNumber.Len() < 3 || PlayerGuess.Len() < 3)
	{
		return 0; // 유효하지 않으면 비교하지 않음
	}
	int32 Balls = 0;
	for (int32 i = 0; i < 3; i++)
	{
		for (int32 j = 0; j < 3; j++)
		{
			if (i != j && SecretNumber[i] == PlayerGuess[j])
			{
				Balls++;
			}
		}
	}

	return Balls;
}

FString UMyBlueprintFunctionJudgment::GetResultString(int32 Strikes, int32 Balls)
{
	// 스트라이크와 볼이 모두 0이면 "OUT" 반환
	if (Strikes == 0 && Balls == 0)
	{
		return TEXT("OUT");
	}

	// 결과 문자열 생성 ("2S1B" 형식)
	return FString::Printf(TEXT("%dS%dB"), Strikes, Balls);
}

bool UMyBlueprintFunctionJudgment::CheckNumber(const FString& PlayerGuess)
{
	return PlayerGuess.Len() == 3;
}

FString UMyBlueprintFunctionJudgment::GenerateUniqueThreeDigitNumber()
{
	TArray<int32> Digits;
	for (int32 i = 0; i <= 9; i++)
	{
		Digits.Add(i);
	}

	// 섞기 (랜덤 셔플)
	for (int32 i = Digits.Num() - 1; i > 0; i--)
	{
		int32 j = FMath::RandRange(0, i);
		Digits.Swap(i, j);
	}

	// 앞에서 3개만 사용
	FString Result = FString::FromInt(Digits[0]) + FString::FromInt(Digits[1]) + FString::FromInt(Digits[2]);
	return Result;
}
FString UMyBlueprintFunctionJudgment::ExtractOnlyGuess(const FString& RawInput)
{
	FString Left, Right;
	if (RawInput.Split(TEXT(":"), &Left, &Right))
	{
		return Right.TrimStartAndEnd(); // "123" 만 추출
	}
	return TEXT(""); // 잘못된 형식
}

bool UMyBlueprintFunctionJudgment::IsGuessCommand(const FString& Input)
{
	return Input.StartsWith(TEXT("/"));
}

FString UMyBlueprintFunctionJudgment::RemoveSlashPrefix(const FString& Input)
{
	FString Result;

	if (Input.StartsWith(TEXT("/")))
	{
		for (int32 i = 1; i < Input.Len(); ++i) // 0번 인덱스는 슬래시니까 제외
		{
			if (FChar::IsDigit(Input[i]))
			{
				Result.AppendChar(Input[i]);
			}
		}
	}


	return Result;
}
