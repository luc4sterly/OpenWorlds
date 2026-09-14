// 004355a0 FUN_004355a0 [Global]
// programa: gamma.dll

float10 __thiscall
FUN_004355a0(undefined4 *param_1,int *param_2,uint param_3,byte *param_4,uint param_5)

{
  void *pvVar1;
  int iVar2;
  float10 fVar3;
  undefined1 local_414 [8];
  byte local_40c [1024];
  
  FUN_00427a20(local_414,param_5);
  pvVar1 = (void *)*param_1;
  FUN_004280b0(local_40c,param_4);
  iVar2 = FUN_00433e90(param_3,(char *)local_40c);
  if (iVar2 != -1) {
    fVar3 = FUN_00432d10(pvVar1,param_2,param_3,-1,iVar2);
    return (float10)(float)fVar3;
  }
  return (float10)DAT_00475524;
}


