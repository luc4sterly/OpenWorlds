// 00402f04 FUN_00402f04 [Global]
// program: sfmain.exe

void __fastcall FUN_00402f04(undefined4 param_1,short *param_2)

{
  short *in_EAX;
  int iVar1;
  undefined2 *unaff_EBX;
  int iVar2;
  
  iVar2 = 1;
  do {
    iVar1 = ((int)*param_2 >> 1) + ((int)*in_EAX >> 1);
    if (0xffff < iVar1 + 0x8000U) {
      if (iVar1 < 1) {
        iVar1 = -0x8000;
      }
      else {
        iVar1 = 0x7fff;
      }
    }
    iVar2 = iVar2 + 1;
    in_EAX = in_EAX + 1;
    param_2 = param_2 + 1;
    *unaff_EBX = (short)iVar1;
    unaff_EBX = unaff_EBX + 1;
  } while (iVar2 < 9);
  return;
}


