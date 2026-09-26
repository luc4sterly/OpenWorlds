// 0040b609 FUN_0040b609 [Global]
// programa: sfmain.exe

undefined8 __fastcall FUN_0040b609(undefined4 param_1,float *param_2)

{
  int in_EAX;
  int iVar1;
  float *unaff_EBX;
  float10 extraout_ST0;
  undefined8 uVar2;
  
  *unaff_EBX = 0.0;
  for (iVar1 = 1; param_2 = param_2 + 1, iVar1 <= in_EAX; iVar1 = iVar1 + 1) {
    *unaff_EBX = *param_2 * *param_2 + *unaff_EBX;
  }
  uVar2 = FUN_0042b7a8(in_EAX,iVar1);
  *unaff_EBX = (float)extraout_ST0;
  return uVar2;
}


