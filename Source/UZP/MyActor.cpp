// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

#include "Components/SplineComponent.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	spline = CreateDefaultSubobject<USplineComponent>("Spline");
	//spline->AttachToComponent(root);

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	FTimerHandle MemberTimerHandle;
	GetWorldTimerManager().SetTimer(MemberTimerHandle, this, &AMyActor::Animate, 0.0175f, true, 2.0f);
	
}

void AMyActor::Animate()
{
	if(Steps[0])
	{
		float length = spline->GetSplineLength();
		Distance = FMath::FInterpConstantTo(Distance,spline->GetSplineLength(),GetWorld()->DeltaTimeSeconds,120);
		FString TheFloatStr = FString::SanitizeFloat(Distance);
		//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TheFloatStr);	
		int Count = Steps.Max()-1;
		float temp;
		for (UStaticMeshComponent* Step : Steps)
		{
			if(Offset * Count + Distance  > spline->GetSplineLength())
			{
				temp=  Distance + (Offset * Count)  - spline->GetSplineLength();
			}
			else
			{
				temp = Distance + (Offset * Count);
			}
			if (Count <3 || Count>Steps.Max() -4 )
			{
				Step->SetWorldLocation(spline->GetLocationAtDistanceAlongSpline(temp,ESplineCoordinateSpace::World));
			}
			else
			{
				Step->SetWorldLocation(spline->GetLocationAtDistanceAlongSpline(temp,ESplineCoordinateSpace::World));
			}
			
			Count--;
		}
		
		if(FMath::IsNearlyEqual(Distance,spline->GetSplineLength(),0.01))
		{
			Distance = 0;
		}
	}
}


// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//Animate();

}

