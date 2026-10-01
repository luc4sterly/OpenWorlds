// 0041efd0 FUN_0041efd0 [Global]
// program: gamma.dll

void __cdecl FUN_0041efd0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  for (iVar1 = FUN_004196d0(param_1); iVar1 != 0; iVar1 = FUN_00419770(iVar1)) {
    for (iVar2 = FUN_004196d0(iVar1); iVar2 != 0; iVar2 = FUN_00419770(iVar2)) {
      for (iVar3 = FUN_004196d0(iVar2); iVar3 != 0; iVar3 = FUN_00419770(iVar3)) {
        for (iVar4 = FUN_004196d0(iVar3); iVar4 != 0; iVar4 = FUN_00419770(iVar4)) {
          for (iVar5 = FUN_004196d0(iVar4); iVar5 != 0; iVar5 = FUN_00419770(iVar5)) {
            for (iVar6 = FUN_004196d0(iVar5); iVar6 != 0; iVar6 = FUN_00419770(iVar6)) {
              for (iVar7 = FUN_004196d0(iVar6); iVar7 != 0; iVar7 = FUN_00419770(iVar7)) {
                for (iVar8 = FUN_004196d0(iVar7); iVar8 != 0; iVar8 = FUN_00419770(iVar8)) {
                  for (iVar9 = FUN_004196d0(iVar8); iVar9 != 0; iVar9 = FUN_00419770(iVar9)) {
                    FUN_0041efd0(iVar9,param_2);
                  }
                  FUN_0041ee70(iVar8,param_2);
                }
                FUN_0041ee70(iVar7,param_2);
              }
              FUN_0041ee70(iVar6,param_2);
            }
            FUN_0041ee70(iVar5,param_2);
          }
          FUN_0041ee70(iVar4,param_2);
        }
        FUN_0041ee70(iVar3,param_2);
      }
      FUN_0041ee70(iVar2,param_2);
    }
    FUN_0041ee70(iVar1,param_2);
  }
  FUN_0041ee70(param_1,param_2);
  return;
}


