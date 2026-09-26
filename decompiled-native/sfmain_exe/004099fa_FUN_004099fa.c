// 004099fa FUN_004099fa [Global]
// programa: sfmain.exe

void __fastcall FUN_004099fa(undefined4 param_1,float *param_2,float param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *in_EAX;
  int iVar4;
  int unaff_EBX;
  
  iVar4 = 1;
  while( true ) {
    param_2 = param_2 + 1;
    in_EAX = in_EAX + 1;
    if (unaff_EBX < iVar4) break;
    fVar1 = *in_EAX;
    fVar2 = *param_4;
    fVar3 = param_4[1];
    iVar4 = iVar4 + 1;
    param_4[1] = *param_4;
    *param_4 = *in_EAX;
    *param_2 = param_3 * fVar3 + (fVar1 - fVar2);
  }
  return;
}


