// 00413780 _Java_NET_worlds_scape_WObject_getClumpMinXYExtent@8 [Global]
// programa: gamma.dll

float10 _Java_NET_worlds_scape_WObject_getClumpMinXYExtent_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  float local_24;
  float local_20;
  float local_1c;
  float local_14;
  float local_10;
  
                    /* 0x13780  354  _Java_NET_worlds_scape_WObject_getClumpMinXYExtent@8 */
  local_24 = DAT_0046f718;
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049fb90);
  if (iVar1 != 0) {
    FUN_00419360(iVar1,&local_20,&local_14);
    local_14 = local_14 - local_20;
    local_24 = local_10 - local_1c;
    if ((byte)(local_14 < local_24 |
              (byte)((ushort)((ushort)(NAN(local_14) || NAN(local_24)) << 10) >> 8)) == 1) {
      local_24 = local_14;
    }
  }
  return (float10)local_24;
}


