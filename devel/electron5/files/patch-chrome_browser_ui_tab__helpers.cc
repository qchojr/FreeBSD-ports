--- chrome/browser/ui/tab_helpers.cc.orig	2019-04-08 08:32:46 UTC
+++ chrome/browser/ui/tab_helpers.cc
@@ -116,7 +116,7 @@
 #include "components/zoom/zoom_controller.h"
 #endif  // defined(OS_ANDROID)
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 #include "chrome/browser/ui/blocked_content/framebust_block_tab_helper.h"
 #include "chrome/browser/ui/hats/hats_helper.h"
 #endif
@@ -309,11 +309,11 @@ void TabHelpers::AttachTabHelpers(WebContents* web_con
 #endif
 
 #if defined(OS_WIN) || defined(OS_MACOSX) || \
-    (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+    (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   metrics::DesktopSessionDurationObserver::CreateForWebContents(web_contents);
 #endif
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
   if (base::FeatureList::IsEnabled(
           features::kHappinessTrackingSurveysForDesktop)) {
     HatsHelper::CreateForWebContents(web_contents);
