function jsonp(req) { var script = document.createElement('script'); var url = req.url + '?callback=' + req.callback.name; script.src = url; document.getElementsByTagName('head')[0].appendChild(script); }
