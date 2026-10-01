// 00445650 FUN_00445650 [Global]
// program: gamma.dll

undefined4
FUN_00445650(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  *(undefined4 *)(param_1 + 0x7c) = param_2;
  *(undefined4 *)(param_1 + 0x80) = param_3;
  *(undefined4 *)(param_1 + 0x84) = param_4;
  *(undefined4 *)(param_1 + 0x88) = param_5;
  *(undefined4 *)(param_1 + 0x8c) = param_6;
  *(undefined4 *)(param_1 + 0x90) = param_7;
  return 0;
}


