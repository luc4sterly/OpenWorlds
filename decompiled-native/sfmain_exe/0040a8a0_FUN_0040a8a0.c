// 0040a8a0 FUN_0040a8a0 [Global]
// program: sfmain.exe

void __fastcall FUN_0040a8a0(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  int iVar3;
  int unaff_EBX;
  
  if (DAT_004386e0 != 0) {
    DAT_004386e0 = 0;
    FUN_0042bdf7(0x168,0);
  }
  for (iVar3 = 0; iVar3 < unaff_EBX; iVar3 = iVar3 + 1) {
    DAT_004386dc = DAT_004386dc + 1;
    *(undefined4 *)(DAT_004386dc * 4 + 0x443408) = *in_EAX;
    if (DAT_004386dc == 600) {
      DAT_004386dc = 0;
    }
    in_EAX = in_EAX + 1;
  }
  puVar1 = param_2 + 0xb4;
  do {
    puVar2 = &DAT_0044340c + DAT_004386d8;
    DAT_004386d8 = DAT_004386d8 + 1;
    *param_2 = *puVar2;
    if (DAT_004386d8 == 600) {
      DAT_004386d8 = 0;
    }
    param_2 = param_2 + 1;
  } while (param_2 != puVar1);
  return;
}


