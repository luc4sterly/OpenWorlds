// 1001d300 RwCreateMatrix [Global]
// programa: RWL21.DLL

undefined4 * RwCreateMatrix(void)

{
  undefined4 *puVar1;
  
                    /* 0x1d300  42  RwCreateMatrix */
  puVar1 = FUN_10037030(DAT_1005ac38);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined1 *)(puVar1 + 0x10) = 0;
    *(undefined1 *)((int)puVar1 + 0x41) = 1;
    puVar1[0xf] = 0x3f800000;
    puVar1[10] = 0x3f800000;
    puVar1[5] = 0x3f800000;
    *puVar1 = 0x3f800000;
    puVar1[0xe] = 0;
    puVar1[0xd] = 0;
    puVar1[0xc] = 0;
    puVar1[0xb] = 0;
    puVar1[9] = 0;
    puVar1[8] = 0;
    puVar1[7] = 0;
    puVar1[6] = 0;
    puVar1[4] = 0;
    puVar1[3] = 0;
    puVar1[2] = 0;
    puVar1[1] = 0;
    *(undefined1 *)((int)puVar1 + 0x41) = 1;
    *(undefined1 *)(puVar1 + 0x10) = 1;
    return puVar1;
  }
  FUN_1000cba0(3);
  return (undefined4 *)0x0;
}


