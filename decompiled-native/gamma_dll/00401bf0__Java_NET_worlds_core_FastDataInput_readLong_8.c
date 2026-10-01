// 00401bf0 _Java_NET_worlds_core_FastDataInput_readLong@8 [Global]
// program: gamma.dll

undefined8 _Java_NET_worlds_core_FastDataInput_readLong_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_14;
  undefined1 uStack_13;
  undefined1 uStack_12;
  undefined1 uStack_11;
  undefined1 local_10;
  undefined1 uStack_f;
  undefined1 uStack_e;
  undefined1 uStack_d;
  
                    /* 0x1bf0  129  _Java_NET_worlds_core_FastDataInput_readLong@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
  if (*(int *)(iVar1 + 8) < 8) {
    if (*(int *)(iVar1 + 0xc) == 0) {
      *(char **)(iVar1 + 0xc) = s_java_io_EOFException_0046d18c;
      *(char **)(iVar1 + 0x10) = s_EOF_Error_0046d1a4;
    }
  }
  else {
    local_14 = *(undefined1 *)(*(int *)(iVar1 + 4) + 7);
    uStack_13 = *(undefined1 *)(*(int *)(iVar1 + 4) + 6);
    uStack_12 = *(undefined1 *)(*(int *)(iVar1 + 4) + 5);
    uStack_11 = *(undefined1 *)(*(int *)(iVar1 + 4) + 4);
    local_10 = *(undefined1 *)(*(int *)(iVar1 + 4) + 3);
    uStack_f = *(undefined1 *)(*(int *)(iVar1 + 4) + 2);
    uStack_e = *(undefined1 *)(*(int *)(iVar1 + 4) + 1);
    uStack_d = **(undefined1 **)(iVar1 + 4);
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 8;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -8;
  }
  if (*(byte **)(iVar1 + 0xc) != (byte *)0x0) {
    FUN_00402930(param_1,*(byte **)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
  }
  return CONCAT17(uStack_d,CONCAT16(uStack_e,CONCAT15(uStack_f,CONCAT14(local_10,CONCAT13(uStack_11,
                                                                                          CONCAT12(
                                                  uStack_12,CONCAT11(uStack_13,local_14)))))));
}


