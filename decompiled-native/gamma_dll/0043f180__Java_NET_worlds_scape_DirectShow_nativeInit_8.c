// 0043f180 _Java_NET_worlds_scape_DirectShow_nativeInit@8 [Global]
// programa: gamma.dll

void _Java_NET_worlds_scape_DirectShow_nativeInit_8(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x3f180  207  _Java_NET_worlds_scape_DirectShow_nativeInit@8 */
  if (DAT_0049def0 == 0) {
    uVar1 = (**(code **)(*param_1 + 0x18))(param_1,s_NET_worlds_scape_DirectShow_00477ca8);
    DAT_0049def0 = (**(code **)(*param_1 + 0x54))(param_1,uVar1);
    if (DAT_0049def0 == 0) {
      FUN_00402800(s_nDirectShow_00477cc4,0x16);
    }
    DAT_0049def4 = (**(code **)(*param_1 + 0x178))
                             (param_1,DAT_0049def0,s_mediaRendererInstancePtr_00477cd4,&DAT_00477cd0
                             );
    if (DAT_0049def4 == 0) {
      FUN_00402800(s_nDirectShow_00477cc4,0x1a);
    }
  }
  return;
}


