<?php

/**
 * For a set of formats, create a table of the settings, descriptions and
 * examples.
 */
function theme_date_format_help_formats($variables) {
  // Pull out $formats from the $variables array
  extract($variables);

  $tables = array();
  $tables['#type'] = 'container';
  $tables['#prefix'] = '<div class="time-formats-help">';
  $tables['#suffix'] = '</div>';

  foreach ($formats as $header => $formatters) {
    $formatter_table = array();
    foreach ($formatters as $key => $value) {
      $formatter_table[] = array(
        $key,
        $value,
        date($key),
      );
    }
    $prefix = '<div class="date-time-formatter-help-block">';
    $prefix .= '<h3>' . $header . '</h3>';
    $tables[] = array(
      '#prefix' => $prefix,
      '#suffix' => '</div>',
      '#theme' => 'table',
      '#rows' => $formatter_table,
    );
  }

  return $tables;
}
