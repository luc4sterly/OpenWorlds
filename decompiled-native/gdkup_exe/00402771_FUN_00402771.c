// 00402771 FUN_00402771 [Global]
// program: gdkup.exe

int __fastcall FUN_00402771(undefined4 param_1,byte *param_2)

{
  byte *in_EAX;
  uint uVar1;
  byte *extraout_ECX;
  uint unaff_EBX;
  int iVar2;
  byte local_14;
  byte local_13;
  
  iVar2 = 0;
  do {
    local_14 = *param_2;
    local_13 = (byte)((ushort)*(undefined2 *)param_2 >> 8);
    uVar1 = FUN_0040355c(in_EAX,&local_14);
    if (uVar1 == 0xffffffff) {
      return -1;
    }
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    if (unaff_EBX < uVar1) {
      return iVar2;
    }
    if (uVar1 != 0) {
      if (1 < uVar1) {
        if (uVar1 != 2) goto LAB_004027d0;
        extraout_ECX[1] = local_13;
      }
      *extraout_ECX = local_14;
    }
LAB_004027d0:
    if (*extraout_ECX == 0) {
      return iVar2;
    }
    param_2 = param_2 + 2;
    in_EAX = extraout_ECX + uVar1;
    iVar2 = iVar2 + uVar1;
    unaff_EBX = unaff_EBX - uVar1;
  } while( true );
}


