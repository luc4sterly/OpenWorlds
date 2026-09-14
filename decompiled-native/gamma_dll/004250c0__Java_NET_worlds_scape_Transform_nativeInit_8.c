// 004250c0 _Java_NET_worlds_scape_Transform_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_Transform_nativeInit_8(int *param_1)

{
  bool bVar1;
  bool bVar2;
  undefined4 uVar3;
  
                    /* 0x250c0  329  _Java_NET_worlds_scape_Transform_nativeInit@8 */
  if (DAT_0049d248 == 0) {
    uVar3 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_Transform_00471b80);
    DAT_0049d248 = (**(code **)(*param_1 + 0x54))(param_1,uVar3);
    if (DAT_0049d248 == 0) {
      FUN_00402800(s_nTransform_00471b9c,0x33);
    }
    DAT_0049d25c = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0049d248,s_noteTransformChange_00471bac,&DAT_00471ba8);
    DAT_0049d260 = (**(code **)(*param_1 + 0x84))
                             (param_1,DAT_0049d248,s_<init>_00471bc0,&DAT_00471ba8);
    DAT_0049d24c = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d248,s_transformID_00471bcc,&DAT_00471bc8);
    bVar1 = false;
    if ((DAT_0049d25c != 0) && (DAT_0049d24c != 0)) {
      bVar1 = true;
    }
    if (!bVar1) {
      FUN_00402800(s_nTransform_00471b9c,0x39);
    }
    if (DAT_0049d260 == 0) {
      FUN_00402800(s_nTransform_00471b9c,0x3a);
    }
    DAT_0049d250 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d248,s_xScale_00471bdc,&DAT_00471bd8);
    DAT_0049d254 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d248,s_yScale_00471be4,&DAT_00471bd8);
    DAT_0049d258 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049d248,s_zScale_00471bec,&DAT_00471bd8);
    bVar1 = false;
    bVar2 = false;
    if ((DAT_0049d250 != 0) && (DAT_0049d254 != 0)) {
      bVar1 = true;
    }
    if ((bVar1) && (DAT_0049d258 != 0)) {
      bVar2 = true;
    }
    if (!bVar2) {
      FUN_00402800(s_nTransform_00471b9c,0x3f);
    }
  }
  return;
}


