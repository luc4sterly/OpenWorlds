// 00403040 Java_NET_worlds_core_Std_GetDiskFreeSpace__Ljava_lang_String_2 [Global]
// program: gamma.dll

/* long __stdcall Java_NET_worlds_core_Std_GetDiskFreeSpace__Ljava_lang_String_2(struct JNIEnv_
   *,class _jclass *,class _jstring *) */

long Java_NET_worlds_core_Std_GetDiskFreeSpace__Ljava_lang_String_2
               (JNIEnv_ *param_1,_jclass *param_2,_jstring *param_3)

{
  BOOL BVar1;
  LPCSTR lpDirectoryName;
  uint uVar2;
  ULARGE_INTEGER local_28;
  ULARGE_INTEGER local_20;
  ULARGE_INTEGER local_18;
  
                    /* 0x3040  2
                       ?Java_NET_worlds_core_Std_GetDiskFreeSpace__Ljava_lang_String_2@@YGJPAUJNIEnv_@@PAV_jclass@@PAV_jstring@@@Z
                        */
  lpDirectoryName = (LPCSTR)0x0;
  if (param_3 != (_jstring *)0x0) {
    lpDirectoryName = (LPCSTR)(**(code **)(*(int *)param_1 + 0x2a4))(param_1,param_3,0);
  }
  uVar2 = 0xffffffff;
  BVar1 = GetDiskFreeSpaceExA(lpDirectoryName,&local_28,&local_18,&local_20);
  if (BVar1 != 0) {
    uVar2 = local_28.s.LowPart >> 10 | local_28.s.HighPart << 0x16;
  }
  if (lpDirectoryName != (LPCSTR)0x0) {
    (**(code **)(*(int *)param_1 + 0x2a8))(param_1,param_3,lpDirectoryName);
  }
  return uVar2;
}


