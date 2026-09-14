// 00417080 _Java_NET_worlds_scape_Material_makeMaterial@40 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int _Java_NET_worlds_scape_Material_makeMaterial_40
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6,int param_7,int param_8,int param_9,
              char param_10)

{
  int iVar1;
  
                    /* 0x17080  251  _Java_NET_worlds_scape_Material_makeMaterial@40 */
  iVar1 = FUN_00419000();
  if (iVar1 == 0) {
    FUN_00402800(s_nMaterial_0047013c,0x73);
  }
  FUN_00419e90(iVar1,(float)param_7 * _DAT_004701cc,(float)param_8 * _DAT_004701cc,
               (float)param_9 * _DAT_004701cc);
  FUN_00419ef0(iVar1,param_3,param_4,param_5);
  FUN_00419ec0(iVar1,param_6);
  if (param_10 == '\0') {
    FUN_00417950(iVar1);
  }
  else {
    FUN_00417a10(iVar1);
  }
  return iVar1;
}


