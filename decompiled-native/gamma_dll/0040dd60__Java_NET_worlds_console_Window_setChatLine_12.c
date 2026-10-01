// 0040dd60 _Java_NET_worlds_console_Window_setChatLine@12 [Global]
// program: gamma.dll

void _Java_NET_worlds_console_Window_setChatLine_12
               (undefined4 param_1,undefined4 param_2,HWND param_3)

{
  int iVar1;
  LONG LVar2;
  int iVar3;
  
                    /* 0xdd60  112  _Java_NET_worlds_console_Window_setChatLine@12 */
  DAT_004a0008 = param_3;
  LVar2 = GetWindowLongA(param_3,-4);
  iVar1 = DAT_00489248;
  iVar3 = 0;
  if (0 < DAT_00489248) {
    do {
      if ((&DAT_00489254)[iVar3] == LVar2) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 < DAT_00489248);
  }
  if (iVar3 == DAT_00489248) {
    if (7 < DAT_00489248) {
      FUN_00403350(0x49eda8,(byte *)s_No_more_window_procedures_for_su_0046e920);
      return;
    }
    DAT_00489248 = DAT_00489248 + 1;
    (&DAT_00489254)[iVar1] = LVar2;
  }
  SetWindowLongA(param_3,-4,(LONG)(&PTR_LAB_0046e900)[iVar3]);
  return;
}


