#include "MyBlueprintFunctionJudgment.h"

int32 UMyBlueprintFunctionJudgment::CountStrikes(const FString& SecretNumber, const FString& PlayerGuess)
{


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
	if (Strikes == 0 && Balls == 0)
		return TEXT("OUT");

	return FString::Printf(TEXT("%dS%dB"), Strikes, Balls);
}

bool UMyBlueprintFunctionJudgment::CheckNumber(const FString& PlayerGuess)
{
	if (PlayerGuess.Len() != 3)
	{
		return false;
	}

	for (int32 i = 0; i < 3; i++)
	{
		if (!FChar::IsDigit(PlayerGuess[i]))
		{
			return false;
		}
	}

	return true; // 3글자이고 모두 숫자
}


FString UMyBlueprintFunctionJudgment::GenerateUniqueThreeDigitNumber()
{
	TArray<int32> Digits;
	for (int32 i = 0; i <= 9; i++)
	{
		Digits.Add(i);
	}

	for (int32 i = Digits.Num() - 1; i > 0; i--)
	{
		int32 j = FMath::RandRange(0, i);
		Digits.Swap(i, j);
	}

	FString Result = FString::FromInt(Digits[0]) + FString::FromInt(Digits[1]) + FString::FromInt(Digits[2]);
	return Result;
}

FString UMyBlueprintFunctionJudgment::ExtractOnlyGuess(const FString& RawInput)
{
	FString Left, Right;
	if (RawInput.Split(TEXT(":"), &Left, &Right))
	{
		return Right.TrimStartAndEnd();
	}
	return TEXT("");
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
		for (int32 i = 1; i < Input.Len(); ++i)
		{
			if (FChar::IsDigit(Input[i]))
			{
				Result.AppendChar(Input[i]);
			}
		}
	}

	return Result;
}


FString UMyBlueprintFunctionJudgment::GetWinMessage(const FString& RawInput)
{
	FString PlayerName, _;
	if (RawInput.Split(TEXT(":"), &PlayerName, &_))
	{
		return PlayerName + TEXT(" win");
	}
	return TEXT("win");
}