// 1001d7c0 RwPopScratchMatrix [Global]
// programa: RWL21.DLL

undefined4 RwPopScratchMatrix(void)

{
  int *piVar1;
  int *piVar2;
  
                    /* 0x1d7c0  308  RwPopScratchMatrix */
  piVar2 = DAT_1005ac44;
  piVar1 = DAT_1005ac44 + 2;
  if (0 < DAT_1005ac44[2]) {
    *piVar1 = DAT_1005ac44[2] + -1;
  }
  return *(undefined4 *)(*piVar2 + *piVar1 * 4);
}


