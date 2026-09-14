// 004019e0 _Java_NET_worlds_core_FastDataInput_readShort@8 [Global]
// programa: gamma.dll

undefined4 _Java_NET_worlds_core_FastDataInput_readShort_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 unaff_SI;
  undefined1 local_e;
  undefined1 uStack_d;
  
                    /* 0x19e0  130  _Java_NET_worlds_core_FastDataInput_readShort@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
  if (*(int *)(iVar1 + 8) < 2) {
    if (*(int *)(iVar1 + 0xc) == 0) {
      *(char **)(iVar1 + 0xc) = s_java_io_EOFException_0046d18c;
      *(char **)(iVar1 + 0x10) = s_EOF_Error_0046d1a4;
    }
  }
  else {
    local_e = *(undefined1 *)(*(int *)(iVar1 + 4) + 1);
    uStack_d = **(undefined1 **)(iVar1 + 4);
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 2;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -2;
  }
  if (*(byte **)(iVar1 + 0xc) != (byte *)0x0) {
    FUN_00402930(param_1,*(byte **)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
  }
  return CONCAT22(unaff_SI,CONCAT11(uStack_d,local_e));
}


