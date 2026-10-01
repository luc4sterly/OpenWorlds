// 100026b0 FUN_100026b0 [Global]
// program: RWL21.DLL

undefined4 FUN_100026b0(void)

{
  DAT_10058030 = FUN_100371c0(s_trianglelist_10058044,0x48);
  DAT_10058034 = FUN_100371c0(s_quadlist_10058038,0x4c);
  if ((DAT_10058030 != (undefined4 *)0x0) && (DAT_10058034 != (undefined4 *)0x0)) {
    return 1;
  }
  return 0;
}


