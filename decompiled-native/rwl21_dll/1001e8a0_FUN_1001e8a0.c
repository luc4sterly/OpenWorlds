// 1001e8a0 FUN_1001e8a0 [Global]
// programa: RWL21.DLL

undefined4 FUN_1001e8a0(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar6 = param_1[2] + *param_1;
  iVar7 = param_1[3] + param_1[1];
  iVar2 = *param_2;
  iVar5 = param_2[2] + iVar2;
  if (*param_1 < iVar5) {
    iVar3 = param_2[1];
    iVar4 = param_2[3] + iVar3;
    if (((param_1[1] < iVar4) && (iVar2 < iVar6)) && (iVar3 < iVar7)) {
      iVar1 = *param_1;
      if (iVar1 <= iVar2) {
        if (((iVar5 <= iVar6) && (param_1[1] <= iVar3)) && (iVar4 <= iVar7)) {
          return 2;
        }
        iVar1 = *param_1;
      }
      if (((iVar2 <= iVar1) && (iVar6 <= iVar5)) && ((iVar3 <= param_1[1] && (iVar7 <= iVar4)))) {
        return 3;
      }
      return 4;
    }
  }
  return 1;
}


