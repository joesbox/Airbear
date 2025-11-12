#include "static_js.h"

String staticJS_updates()
{
    String js = "";
    js += "<script>";
    js += R"(
    function s(e){return document.getElementById(e)}function i(e,t){return e=e.replace('v',''),t=t.replace('v',''),e.startsWith(t+'-')?-1:t.startsWith(e+'-')?1:e.localeCompare(t,void 0,{numeric:!0,sensitivity:'case',caseFirst:'upper'})}function r(e){return e.browser_download_url.split('/').pop()}async function getLatestGithubRelease(e){var t,a=await(await fetch('https://api.github.com/repos/speeduino/AirBear/releases/latest')).json(),n=a.tag_name;if(1==i(s('latest_release_txt').innerHTML=n,e)){s('update_btn').disabled=!1;for(const o of a.assets)o.name.includes('littlefs')?(t='http://speeduino.com/fw/AirBear/'+n+'/'+r(o),s('newData_url').value=t,console.log('Data file: '+t)):(t='http://speeduino.com/fw/AirBear/'+n+'/'+r(o),s('newFW_url').value=t,console.log('FW file: '+t))}}async function scanWifi(){var e=s('ssid');for(const a of(await(await fetch('/wifi')).json()).networks){var t=document.createElement('option');t.value=a.ssid,t.text=a.ssid,e.add(t)}}function toggleData(){var e=s('newData_url');e.disabled=!e.disabled}function a(e,t){e.innerHTML=t}function updateProgress(){setTimeout(async()=>{let e;try{var t=await fetch('/updateStatus');e=await t.json()}catch(e){console.log(e),updateProgress()}e&&(a(s('updateStatus'),e.updateStatus),a(s('updateComplete'),e.updateProgress),a(s('updateSize'),e.updateSize),t=Math.floor(e.updateProgress/e.updateSize*100),a(s('updatePercent'),t),console.log(t),98<=t?setTimeout(()=>{const e=window.location;e.href='/',e=e.href},7e3):updateProgress())},1100)}const e=new EventSource('/events');e.addEventListener('debug',function(e){s('debug_text').value+=e.data+'\n'},!1);
    )";
    js += "</script>";

    return js;
}