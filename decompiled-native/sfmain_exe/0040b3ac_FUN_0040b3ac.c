// 0040b3ac FUN_0040b3ac [Global]
// programa: sfmain.exe

void __fastcall FUN_0040b3ac(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint in_EAX;
  int *unaff_EBX;
  uint uVar3;
  
  uVar3 = in_EAX & 0xff ^ (int)(in_EAX & 0xff) >> 4;
  uVar3 = uVar3 ^ (int)uVar3 >> 2;
  uVar1 = *(uint *)(&DAT_004386f8 + (in_EAX & 0x7f) * 4);
  uVar3 = (uVar3 ^ uVar3 / 2) & 1;
  *param_2 = uVar1 & 0xf;
  if ((uVar1 & 0x10) == 0) {
    iVar2 = *unaff_EBX;
    *unaff_EBX = iVar2 + 1;
    if (uVar3 == 0) {
      *unaff_EBX = iVar2 + 2;
      *param_2 = 0xffffffff;
    }
  }
  else if (uVar3 != 0) {
    *unaff_EBX = *unaff_EBX + 1;
    return;
  }
  return;
}


