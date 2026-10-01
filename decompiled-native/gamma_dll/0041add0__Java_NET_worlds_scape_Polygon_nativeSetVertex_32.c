// 0041add0 _Java_NET_worlds_scape_Polygon_nativeSetVertex@32 [Global]
// program: gamma.dll

void _Java_NET_worlds_scape_Polygon_nativeSetVertex_32
               (int *param_1,undefined4 param_2,int param_3,undefined4 param_4,undefined4 param_5,
               undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  
                    /* 0x1add0  261  _Java_NET_worlds_scape_Polygon_nativeSetVertex@32 */
  iVar1 = FUN_00412cf0(param_1,param_2);
  if (iVar1 != 0) {
    local_1c = param_4;
    local_14 = param_6;
    local_18 = param_5;
    FUN_00419dd0(iVar1,param_3 + 1,&local_1c);
    FUN_00419e00(iVar1,param_3 + 1,param_7,param_8);
    FUN_00417a90(iVar1);
  }
  return;
}


