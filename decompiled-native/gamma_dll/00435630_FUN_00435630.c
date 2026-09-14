// 00435630 FUN_00435630 [Global]
// programa: gamma.dll

float10 __thiscall FUN_00435630(int *param_1,int *param_2,uint param_3,byte *param_4)

{
  int iVar1;
  int iVar2;
  float10 fVar3;
  byte local_40c [1024];
  
  iVar1 = *param_1;
  FUN_004280b0(local_40c,param_4);
  iVar2 = FUN_00433e90(param_3,(char *)local_40c);
  if (iVar2 != -1) {
    fVar3 = FUN_00432be0(iVar1,param_2,param_3,iVar2);
    return fVar3;
  }
  return (float10)DAT_00475524;
}


