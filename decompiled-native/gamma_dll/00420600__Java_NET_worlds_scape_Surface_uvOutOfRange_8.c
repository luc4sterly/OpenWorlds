// 00420600 _Java_NET_worlds_scape_Surface_uvOutOfRange@8 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 _Java_NET_worlds_scape_Surface_uvOutOfRange_8(int *param_1,undefined4 param_2)

{
  byte bVar3;
  uint uVar1;
  undefined4 uVar2;
  int iVar4;
  ushort uVar5;
  float local_14;
  float local_10;
  
                    /* 0x20600  304  _Java_NET_worlds_scape_Surface_uvOutOfRange@8 */
  uVar1 = FUN_00412d20(param_1,param_2);
  if ((uVar1 & 0x100000) != 0) {
    return (short)CONCAT31((int3)(uVar1 >> 8),1);
  }
  if ((uVar1 & 0x80000) != 0) {
    return 1;
  }
  uVar2 = FUN_00412cf0(param_1,param_2);
  iVar4 = 1;
  while( true ) {
    FUN_00419610(uVar2,iVar4,&local_14,&local_10);
    bVar3 = local_14 < DAT_004712ac |
            (byte)((ushort)((ushort)(NAN(local_14) || NAN(DAT_004712ac)) << 10) >> 8);
    uVar1 = (uint)bVar3 << 8;
    if (bVar3 == 1) break;
    uVar5 = (ushort)(local_14 < _DAT_004712b0) << 8 |
            (ushort)(NAN(local_14) || NAN(_DAT_004712b0)) << 10 |
            (ushort)(local_14 == _DAT_004712b0) << 0xe;
    uVar1 = (uint)uVar5;
    if (((char)(uVar5 >> 8) == '\0') ||
       (bVar3 = local_10 < DAT_004712ac |
                (byte)((ushort)((ushort)(NAN(local_10) || NAN(DAT_004712ac)) << 10) >> 8),
       uVar1 = (uint)bVar3 << 8, bVar3 == 1)) break;
    uVar5 = (ushort)(local_10 < _DAT_004712b0) << 8 |
            (ushort)(NAN(local_10) || NAN(_DAT_004712b0)) << 10 |
            (ushort)(local_10 == _DAT_004712b0) << 0xe;
    uVar1 = (uint)uVar5;
    if ((char)(uVar5 >> 8) == '\0') break;
    iVar4 = iVar4 + 1;
    if (4 < iVar4) {
      return uVar5;
    }
  }
  return (short)CONCAT31((int3)(uVar1 >> 8),1);
}


