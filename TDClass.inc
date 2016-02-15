<?php

use Tracy\Debugger;

class TD {

	/**
	 * These are here so that they are available even when non-superuser or module not enabled so we
	 * don't get a undefined function error when calling these from a template file.
	 */

    /**
     * Tracy\Debugger::barDump() shortcut.
     * @tracySkipLocation
     */
    public static function barDump($var, $title = NULL, array $options = NULL) {
        if(!wire('user')->isSuperuser() || !class_exists('\Tracy\Debugger')) return false;
        return Debugger::barDump($var, $title, $options);
    }

    /**
     * Tracy\Debugger::dump() shortcut.
     * @tracySkipLocation
     */
    public static function dump($var, $return = FALSE) {
        if(!wire('user')->isSuperuser() || !class_exists('\Tracy\Debugger')) return false;
        return Debugger::dump($var, $return);
    }

    /**
     * Tracy\Debugger::log() shortcut.
     * @tracySkipLocation
     */
    public static function log($message, $priority = Debugger::INFO) {
        if(!wire('user')->isSuperuser() || !class_exists('\Tracy\Debugger')) return false;
        return Debugger::log($message, $priority);
    }

    /**
     * Tracy\Debugger::timer() shortcut.
     * @tracySkipLocation
     */
    public static function timer($name = NULL) {
        if(!wire('user')->isSuperuser() || !class_exists('\Tracy\Debugger')) return false;
        $roundedTime = round(Debugger::timer($name),4);
        if($name) {
            return $name.' : '.$roundedTime;
        }
        else{
            return $roundedTime;
        }
    }

    /**
     * Tracy\Debugger::fireLog() shortcut.
     * @tracySkipLocation
     */
    public static function fireLog($message = NULL) {
        if(!wire('user')->isSuperuser() || !class_exists('\Tracy\Debugger')) return false;
        return Debugger::fireLog($message);
    }

}
