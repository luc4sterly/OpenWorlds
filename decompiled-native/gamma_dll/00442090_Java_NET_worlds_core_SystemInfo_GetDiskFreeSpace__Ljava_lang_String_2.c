// 00442090 Java_NET_worlds_core_SystemInfo_GetDiskFreeSpace__Ljava_lang_String_2 [Global]
// programa: gamma.dll

/* long __stdcall Java_NET_worlds_core_SystemInfo_GetDiskFreeSpace__Ljava_lang_String_2(struct
   JNIEnv_ *,class _jclass *,class _jstring *) */

long Java_NET_worlds_core_SystemInfo_GetDiskFreeSpace__Ljava_lang_String_2
               (JNIEnv_ *param_1,_jclass *param_2,_jstring *param_3)

{
  BOOL BVar1;
  uint uVar2;
  LPCSTR lpRootPathName;
  DWORD local_20;
  DWORD local_1c;
  DWORD local_18;
  DWORD local_14;
  
                    /* 0x42090  3
                       ?Java_NET_worlds_core_SystemInfo_GetDiskFreeSpace__Ljava_lang_String_2@@YGJPAUJNIEnv_@@PAV_jclass@@PAV_jstring@@@Z
                        */
  lpRootPathName = (LPCSTR)0x0;
  if (param_3 != (_jstring *)0x0) {
    lpRootPathName = (LPCSTR)(**(code **)(*(int *)param_1 + 0x2a4))(param_1,param_3,0);
  }
  uVar2 = 0;
  BVar1 = GetDiskFreeSpaceA(lpRootPathName,&local_14,&local_18,&local_1c,&local_20);
  if (BVar1 != 0) {
    uVar2 = local_18 * local_14 * local_1c >> 10;
  }
  if (lpRootPathName != (LPCSTR)0x0) {
    (**(code **)(*(int *)param_1 + 0x2a8))(param_1,param_3,lpRootPathName);
  }
  return uVar2;
}


