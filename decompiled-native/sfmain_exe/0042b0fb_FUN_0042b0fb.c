// 0042b0fb FUN_0042b0fb [Global]
// programa: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042b0fb(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int local_1c;
  
  if (_DAT_004e579c == 0) {
    puVar2 = &DAT_0043dff8;
    puVar3 = (undefined4 *)&DAT_004e4d84;
    for (iVar1 = 0x143; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    puVar2 = &DAT_0043daec;
    puVar3 = (undefined4 *)&DAT_004e5290;
    for (iVar1 = 0x143; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (local_1c = 0; local_1c < 0x14; local_1c = local_1c + 1) {
      *(undefined **)(&DAT_0043e3c4 + local_1c * 4) = &DAT_0043e004 + local_1c * 0xc;
      *(undefined **)(&DAT_0043e414 + local_1c * 4) = &DAT_0043e0f4 + local_1c * 0xc;
      *(undefined **)(&DAT_0043e464 + local_1c * 4) = &DAT_0043e1e4 + local_1c * 0xc;
      *(undefined **)(&DAT_0043e4b4 + local_1c * 4) = &DAT_0043e2d4 + local_1c * 0xc;
      *(int *)(local_1c * 4 + 0x4e5150) = local_1c * 0xc + 0x4e4d90;
      *(int *)(local_1c * 4 + 0x4e51a0) = local_1c * 0xc + 0x4e4e80;
      *(int *)(local_1c * 4 + 0x4e51f0) = local_1c * 0xc + 0x4e4f70;
      *(int *)(local_1c * 4 + 0x4e5240) = local_1c * 0xc + 0x4e5060;
      *(undefined **)(&DAT_0043deb8 + local_1c * 4) = &DAT_0043daf8 + local_1c * 0xc;
      *(undefined **)(&DAT_0043df08 + local_1c * 4) = &DAT_0043dbe8 + local_1c * 0xc;
      *(undefined **)(&DAT_0043df58 + local_1c * 4) = &DAT_0043dcd8 + local_1c * 0xc;
      *(undefined **)(&DAT_0043dfa8 + local_1c * 4) = &DAT_0043ddc8 + local_1c * 0xc;
      *(int *)(local_1c * 4 + 0x4e565c) = local_1c * 0xc + 0x4e529c;
      *(int *)(local_1c * 4 + 0x4e56ac) = local_1c * 0xc + 0x4e538c;
      *(int *)(local_1c * 4 + 0x4e56fc) = local_1c * 0xc + 0x4e547c;
      *(int *)(local_1c * 4 + 0x4e574c) = local_1c * 0xc + 0x4e556c;
    }
    _DAT_004e579c = 1;
  }
  return;
}


