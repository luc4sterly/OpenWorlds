// 10025200 FUN_10025200 [Global]
// program: RWDLDD21.DLL

uint FUN_10025200(uint *param_1)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar1;
  undefined4 extraout_EDX;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  int local_c;
  int local_8;
  int local_4;
  
  switch(DAT_10039088) {
  case 1:
  case 2:
  case 4:
    return (param_1[1] & 0xff00) << 8 | param_1[2] & 0xff00 | (*param_1 & 0xffffff00) << 0x10;
  default:
    return 0;
  case 8:
    break;
  case 0xf:
    return (int)((int)((param_1[2] & 0xf800) >> 5 | param_1[1] & 0xf800) >> 5 | *param_1 & 0xf800)
           >> 1;
  case 0x10:
    return ((param_1[2] & 0xf800) >> 6 | param_1[1] & 0xfc00) >> 5 | *param_1 & 0xf800;
  }
  uVar2 = ((param_1[1] & 0xfc00) >> 5 | *param_1 & 0xfffff800) << 0x10 | (param_1[2] & 0xf800) << 5;
  FUN_100253b0((int *)param_1,&local_c);
  uVar4 = FUN_10033000(extraout_ECX,extraout_EDX,local_8,0x40000);
  uVar3 = ((int)uVar4 + 0x8000 >> 0x10) - 1;
  if ((-1 < local_c) && (-1 < (int)uVar3)) {
    uVar4 = FUN_10033000(extraout_ECX_00,(int)((ulonglong)uVar4 >> 0x20),local_c,0x60000);
    if ((uVar3 & 1) == 0) {
      iVar1 = local_4 * 0x18 >> 0x10;
    }
    else {
      iVar1 = 0x1f - (local_4 * 0x18 >> 0x10);
    }
    return uVar2 | (uVar3 + (int)(CONCAT44((int)uVar4 >> 0x1f,(int)uVar4 >> 0x10) % 0x24) * 4) *
                   0x20 + iVar1;
  }
  return uVar2 | (local_4 * 0x1f >> 0x10) + 0x1200U;
}


