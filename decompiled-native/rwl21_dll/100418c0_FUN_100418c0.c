// 100418c0 FUN_100418c0 [Global]
// programa: RWL21.DLL

undefined4 FUN_100418c0(void)

{
  float fVar1;
  uint uVar2;
  int iVar3;
  float local_c;
  
  uVar2 = 0;
  DAT_1005b8c0 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x4000);
  if (DAT_1005b8c0 == 0) {
    FUN_1000cba0(3);
  }
  else {
    local_c = 1.0;
    do {
      uVar2 = uVar2 + 4;
      *(int *)(DAT_1005b8c0 + -4 + uVar2) = (int)SQRT(local_c) + -0x1fc00000;
      local_c = (float)((int)local_c + 0x1000);
    } while (uVar2 < 0x2000);
    DAT_1005b8c4 = DAT_1005b8c0 + 0x2000;
    uVar2 = 0;
    do {
      uVar2 = uVar2 + 4;
      *(int *)(DAT_1005b8c4 + -4 + uVar2) = (int)SQRT(local_c) + -0x20000000;
      local_c = (float)((int)local_c + 0x1000);
    } while (uVar2 < 0x2000);
  }
  iVar3 = 0;
  if (DAT_1005b8c0 != 0) {
    DAT_1005b8c8 = (**(code **)(PTR_DAT_1005b69c + 0x34c))(0x3004);
    if (DAT_1005b8c8 == 0) {
      FUN_1000cba0(3);
    }
    else {
      fVar1 = 1.0;
      do {
        iVar3 = iVar3 + 4;
        *(uint *)(DAT_1005b8c8 + -4 + iVar3) =
             ((uint)SQRT(fVar1) & 0x7fffff | 0x800000) <<
             ((byte)((int)SQRT(fVar1) + 0xc0800000U >> 0x17) & 0x1f);
        fVar1 = fVar1 + 0.0009765625;
      } while (iVar3 < 0x3001);
    }
    if (DAT_1005b8c8 != 0) {
      return 1;
    }
  }
  return 0;
}


