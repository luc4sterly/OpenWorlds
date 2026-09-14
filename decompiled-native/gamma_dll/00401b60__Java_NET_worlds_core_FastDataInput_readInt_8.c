// 00401b60 _Java_NET_worlds_core_FastDataInput_readInt@8 [Global]
// programa: gamma.dll

undefined4 _Java_NET_worlds_core_FastDataInput_readInt_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 local_10;
  
                    /* 0x1b60  128  _Java_NET_worlds_core_FastDataInput_readInt@8 */
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_00489024);
  if (*(int *)(iVar1 + 8) < 4) {
    if (*(int *)(iVar1 + 0xc) == 0) {
      *(char **)(iVar1 + 0xc) = s_java_io_EOFException_0046d18c;
      *(char **)(iVar1 + 0x10) = s_EOF_Error_0046d1a4;
    }
  }
  else {
    local_10 = CONCAT13(**(undefined1 **)(iVar1 + 4),
                        CONCAT12(*(undefined1 *)(*(int *)(iVar1 + 4) + 1),
                                 CONCAT11(*(undefined1 *)(*(int *)(iVar1 + 4) + 2),
                                          *(undefined1 *)(*(int *)(iVar1 + 4) + 3))));
    *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + 4;
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + -4;
  }
  if (*(byte **)(iVar1 + 0xc) != (byte *)0x0) {
    FUN_00402930(param_1,*(byte **)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x10));
  }
  return local_10;
}


